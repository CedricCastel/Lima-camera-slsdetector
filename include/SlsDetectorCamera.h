//###########################################################################
// This file is part of LImA, a Library for Image Acquisition
//
// Copyright (C) : 2009-2011
// European Synchrotron Radiation Facility
// BP 220, Grenoble 38043
// FRANCE
//
// This is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//###########################################################################

#ifndef __SLS_DETECTOR_CAMERA_H
#define __SLS_DETECTOR_CAMERA_H

#include "SlsDetectorArgs.h"
#include "SlsDetectorDefs.h"

#include "multiSlsDetector.h"
#include "slsReceiverUsers.h"

#include "lima/RegExUtils.h"
#include "lima/HwBufferMgr.h"
#include "lima/HwMaxImageSizeCallback.h"
#include "lima/Event.h"

#include <set>
#include <queue>


namespace lima 
{

namespace SlsDetector
{

template <class T>
class PrettyList
{
 public:
	typedef typename T::const_iterator const_iterator;

	PrettyList(const T& l) : begin(l.begin()), end(l.end()) {}
	PrettyList(const_iterator b, const_iterator e) : begin(b), end(e) {}

	ostream& print(ostream& os) const
	{
		os << "[";
		int prev;
		bool in_seq = false;
		bool first = true;
		for (const_iterator it = begin; it != end; ++it) {
			int val = *it;
			bool seq = (!first && (val == prev + 1));
			if (!seq) {
				if (in_seq)
					os << "-" << prev;
				os << (first ? "" : ",") << val;
			}
			prev = val;
			in_seq = seq;
			first = false;
		}
		if (in_seq)
			os << "-" << prev;
		return os << "]";
	}

 private:
	const_iterator begin, end;
};

template <class T>
std::ostream& operator <<(std::ostream& os, const PrettyList<T>& pl)
{
	return pl.print(os);
}


class Camera : public HwMaxImageSizeCallbackGen, public EventCallbackGen
{
	DEB_CLASS_NAMESPC(DebModCamera, "Camera", "SlsDetector");

public:
	typedef Defs::TrigMode TrigMode;
	typedef Defs::Settings Settings;
	typedef Defs::DACIndex DACIndex;
	typedef Defs::ADCIndex ADCIndex;
	typedef Defs::ClockDiv ClockDiv;
	typedef Defs::ReadoutFlags ReadoutFlags;

	enum State {
		Idle, Init, Starting, Running, StopReq, Stopping, Stopped,
	};

	enum Type {
		UnknownDet, GenericDet, EigerDet, JungfrauDet,
	};

	enum PixelDepth {
		PixelDepth4 = 4, 
		PixelDepth8 = 8, 
		PixelDepth16 = 16, 
		PixelDepth32 = 32,
	};

	typedef uint64_t FrameType;
	typedef std::vector<std::string> NameList;
	typedef std::vector<int> IntList;
	typedef std::vector<double> FloatList;

	class Model
	{
		DEB_CLASS_NAMESPC(DebModCamera, "Camera::Model", "SlsDetector");
	public:
		Model(Camera *cam, Type type);
		virtual ~Model();
	
		virtual void getFrameDim(FrameDim& frame_dim, 
					 bool raw = false) = 0;
		
		Camera *getCamera()
		{ return m_cam; }

		Type getType()
		{ return m_type; }

		virtual std::string getName() = 0;
		virtual void getPixelSize(double& x_size, double& y_size) = 0;

		virtual void getDACInfo(NameList& name_list, 
					IntList& idx_list,
					IntList& milli_volt_list) = 0;
		virtual void getADCInfo(NameList& name_list, 
					IntList& idx_list,
					FloatList& factor_list, 
					FloatList& min_val_list) = 0;

	protected:
		void updateCameraModel();

		virtual void updateImageSize() = 0;

		void putCmd(const std::string& s, int idx = -1);
		std::string getCmd(const std::string& s, int idx = -1);

		virtual bool checkSettings(Settings settings) = 0;

		virtual ReadoutFlags getReadoutFlagsMask() = 0;
		virtual bool checkReadoutFlags(ReadoutFlags flags,
					       IntList& flag_list,
					       bool silent = false) = 0;

		virtual int getRecvPorts() = 0;

		virtual void prepareAcq() = 0;
		virtual void processRecvFileStart(int port_idx,
						  uint32_t dsize) = 0;
		// TODO: add file finished callback
		virtual void processRecvPort(int port_idx, FrameType frame, 
					     char *dptr, uint32_t dsize, 
					     char *bptr) = 0;

	private:
		friend class Camera;
		Camera *m_cam;
		Type m_type;
	};

	class FrameMap
	{
		DEB_CLASS_NAMESPC(DebModCamera, "Camera::FrameMap", 
				  "SlsDetector");

	public:
		typedef std::set<int> List;
		typedef std::map<FrameType, List> Map;

		class Callback
		{
			DEB_CLASS_NAMESPC(DebModCamera, 
					  "Camera::FrameMap::Callback", 
					  "SlsDetector");

		public:
			Callback();
			virtual ~Callback();
		protected:
			virtual void frameFinished(FrameType frame) = 0;
		private:
			friend class FrameMap;
			FrameMap *m_map;
		};

		FrameMap(bool debug = true);
		~FrameMap();
		
		void setCallback(Callback *cb);
		void setNbItems(int nb_items);
		void clear();

		void checkFinishedFrameItem(FrameType frame, int item);
		void frameItemFinished(FrameType frame, int item, 
				       bool no_check = false);

		FrameType getLastItemFrame() const;

		FrameType getLastSeqFinishedFrame() const
		{ return m_last_seq_finished_frame; }

		const List& getNonSeqFinishedFrames() const
		{ return m_non_seq_finished_frames; }

		const Map& getFramePendingItemsMap() const
		{ return m_map; }

		static bool isValidFrame(FrameType frame)
		{ return (frame != FrameType(-1)); }

		static FrameType latestFrame(FrameType a, FrameType b)
		{
			if (!isValidFrame(a))
				return b;
			if (!isValidFrame(b))
				return a;
			return (a > b) ? a : b;
		}

	private:
		friend class Callback;

		int m_nb_items;
		Map m_map;
		List m_non_seq_finished_frames;
		FrameType m_last_seq_finished_frame;
		Callback *m_cb;
		bool m_debug;
	};

	Camera(std::string config_fname);
	virtual ~Camera();

	Type getType();

	Model *getModel()
	{ return m_model; }

	NameList getHostnameList()
	{ return m_input_data->host_name_list; }

	int getNbDetModules()
	{ return m_input_data->host_name_list.size(); }

	int getNbDetSubModules()
	{ return m_det->getNMods(); }

	int getPortIndex(int recv_idx, int port)
	{ return recv_idx * m_recv_ports + port; }

	void setBufferCbMgr(StdBufferCbMgr *buffer_cb_mgr)
	{ m_buffer_cb_mgr = buffer_cb_mgr; }

	void setPixelDepth(PixelDepth  pixel_depth);
	void getPixelDepth(PixelDepth& pixel_depth);

	void setRawMode(bool  raw_mode);
	void getRawMode(bool& raw_mode);

	State getState();
	void waitState(State state);
	State waitNotState(State state);

	ImageType getImageType() const
	{ return m_image_type; }

	void getFrameDim(FrameDim& frame_dim, bool raw = false)
	{ m_model->getFrameDim(frame_dim, raw); }

	const FrameMap& getFrameMap()
	{ return m_frame_map; }

	void putCmd(const std::string& s, int idx = -1);
	std::string getCmd(const std::string& s, int idx = -1);

	int getFramesCaught();
	std::string getStatus();

	void setTrigMode(TrigMode  trig_mode);
	void getTrigMode(TrigMode& trig_mode);
	void setNbFrames(FrameType  nb_frames);
	void getNbFrames(FrameType& nb_frames);
	void setExpTime(double  exp_time);
	void getExpTime(double& exp_time);
	void setFramePeriod(double  frame_period);
	void getFramePeriod(double& frame_period);

	// setDAC: sub_mod_idx: 0-N=sub_module, -1=all
	void setDAC(int sub_mod_idx, DACIndex dac_idx, int  val, 
		    bool milli_volt = false);
	void getDAC(int sub_mod_idx, DACIndex dac_idx, int& val, 
		    bool milli_volt = false);
	void getDACList(DACIndex dac_idx, IntList& val_list,
			bool milli_volt = false);

	void getADC(int sub_mod_idx, ADCIndex adc_idx, int& val);
	void getADCList(ADCIndex adc_idx, IntList& val_list);

	void setAllTrimBits(int sub_mod_idx, int  val);
	void getAllTrimBits(int sub_mod_idx, int& val);
	void getAllTrimBitsList(IntList& val_list);

	void setSettings(Settings  settings);
	void getSettings(Settings& settings);
	void setThresholdEnergy(int  thres);
	void getThresholdEnergy(int& thres);

	void setClockDiv(ClockDiv  clock_div);
	void getClockDiv(ClockDiv& clock_div);
	void setReadoutFlags(ReadoutFlags  flags);
	void getReadoutFlags(ReadoutFlags& flags);
	void getValidReadoutFlags(IntList& flag_list, NameList& flag_name_list);

	void setTolerateLostPackets(bool  tol_lost_packets);
	void getTolerateLostPackets(bool& tol_lost_packets);
	void getBadFrameList(IntList& bad_frame_list);

	void prepareAcq();
	void startAcq();
	void stopAcq();

	int getNbHwAcquiredFrames();
	
private:
	typedef RegEx::SingleMatchType SingleMatch;
	typedef RegEx::FullMatchType FullMatch;
	typedef RegEx::MatchListType MatchList;
	typedef MatchList::const_iterator MatchListIt;

	typedef std::vector<std::string> StringList;
	typedef std::map<int, int> RecvPortMap;
	typedef std::map<int, int> FrameRecvMap;

	typedef std::queue<int> FrameQueue;

	struct AppInputData
	{
		DEB_CLASS_NAMESPC(DebModCamera, "Camera::AppInputData", 
				  "SlsDetector");
	public:
		std::string config_file_name;
		NameList host_name_list;
		RecvPortMap recv_port_map;
		AppInputData(std::string cfg_fname);
		void parseConfigFile();
	};

	class Receiver 
	{
		DEB_CLASS_NAMESPC(DebModCamera, "Camera::Receiver", 
				  "SlsDetector");

	public:
		Receiver(Camera *cam, int idx, int rx_port);
		~Receiver();
		void start();

	private:
		friend class Camera;

		static int fileStartCallback(char *fpath, char *fname, 
					 FrameType fidx, uint32_t dsize, 
					 void *priv);

		static void portCallback(FrameType frame, 
					 uint32_t exp_len,
					 uint32_t recv_packets,
					 uint64_t bunch_id,
					 uint64_t timestamp,
					 uint16_t mod_id,
					 uint16_t x, uint16_t y, uint16_t z,
					 uint32_t debug,
					 uint16_t rr_nb,
					 uint8_t det_type,
					 uint8_t cb_version,
					 char *dptr, 
					 uint32_t dsize, 
					 void *priv);
		int fileStartCallback(char *fpath, char *fname, uint64_t fidx, 
				      uint32_t dsize);
		void portCallback(FrameType frame, int port, char *dptr, 
				  uint32_t dsize);

		Camera *m_cam;
		int m_idx;
		int m_rx_port;
		Args m_args;
		AutoPtr<slsReceiverUsers> m_recv;
	}; 

	typedef std::vector<AutoPtr<Receiver> > RecvList;

	class AcqThread : public Thread
	{
		DEB_CLASS_NAMESPC(DebModCamera, "Camera::AcqThread", 
				  "SlsDetector");
	public:
		AcqThread(Camera *cam);
		void stop(bool wait);
	protected:
		virtual void threadFunction();
	private:
		bool newFrameReady(FrameType frame);

		Camera *m_cam;
		Cond& m_cond;
		volatile State& m_state;
		FrameQueue& m_frame_queue;
	};

	class FrameFinishedCallback : public FrameMap::Callback
	{
		DEB_CLASS_NAMESPC(DebModCamera, 
				  "Camera::FrameFinishedCallback", 
				  "SlsDetector");
	public:
		FrameFinishedCallback(Camera *cam);
	protected:
		virtual void frameFinished(FrameType frame);
	private:
		Camera *m_cam;
	};

	friend class Model;

	void setModel(Model *model);

	AutoMutex lock()
	{ return AutoMutex(m_cond.mutex()); }

	void updateImageSize();

	int64_t NSec(double x)
	{ return int64_t(x * 1e9); }

	State getEffectiveState();

	char *getFrameBufferPtr(FrameType frame_nb);
	void removeSharedMem();
	void createReceivers();

	void frameFinished(FrameType frame);

	bool checkLostPackets();
	void handleLostPackets();
	FrameType getLastReceivedFrame();

	void addValidReadoutFlags(DebObj *deb_ptr, ReadoutFlags flags, 
				  IntList& flag_list, NameList& flag_name_list);

	template <class T>
	void putNbCmd(const std::string& cmd, T val, int idx = -1)
	{
		std::ostringstream os;
		os << cmd << " " << val;
		putCmd(os.str(), idx);
	}

	template <class T>
	T getNbCmd(const std::string& cmd, int idx = -1)
	{
		std::string ans = getCmd(cmd, idx);
		std::istringstream is(ans);
		T val;
		is >> val;
		return val;
	}

	Model *m_model;
	Cond m_cond;
	AutoPtr<AppInputData> m_input_data;
	RecvList m_recv_list;
	AutoPtr<multiSlsDetector> m_det;
	TrigMode m_trig_mode;
	FrameType m_nb_frames;
	double m_exp_time;
	double m_frame_period;
	Settings m_settings;
	FrameMap m_frame_map;
	int m_recv_ports;
	AutoPtr<FrameFinishedCallback> m_frame_cb;
	StdBufferCbMgr *m_buffer_cb_mgr;
	PixelDepth m_pixel_depth;
	ImageType m_image_type;
	bool m_raw_mode;
	AutoPtr<AcqThread> m_acq_thread;
	volatile State m_state;
	FrameQueue m_frame_queue;
	double m_new_frame_timeout;
	double m_abort_sleep_time;
	bool m_tol_lost_packets;
	IntList m_bad_frame_list;
};

std::ostream& operator <<(std::ostream& os, Camera::State state);
std::ostream& operator <<(std::ostream& os, Camera::Type type);

std::ostream& operator <<(std::ostream& os, const Camera::FrameMap& m);
std::ostream& operator <<(std::ostream& os, const Camera::FrameMap::List& l);
std::ostream& operator <<(std::ostream& os, const Camera::FrameMap::Map& m);


} // namespace SlsDetector

} // namespace lima



#endif // __SLS_DETECTOR_CAMERA_H
