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

namespace SlsDetector
{

%TypeHeaderCode
#include "SlsDetectorEiger.h"
%End


class Eiger : public SlsDetector::Camera::Model
{

%TypeHeaderCode
#include "SlsDetectorEiger.h"
%End

 public:
	class Correction : public LinkTask
	{
	public:
		Correction(SlsDetector::Eiger *eiger);

		virtual Data process(Data& data);
	};

	Eiger(SlsDetector::Camera *cam);

	virtual void getFrameDim(FrameDim& frame_dim /Out/, bool raw = false);
	SlsDetector::Eiger::Correction *createCorrectionTask() /Factory/;

	virtual std::string getName();
	virtual void getPixelSize(double& x_size /Out/, double& y_size /Out/);

	virtual void getDACInfo(std::vector<std::string>& name_list /Out/,
				std::vector<int>& idx_list /Out/, 
				std::vector<int>& milli_volt_list /Out/);
	virtual void getADCInfo(std::vector<std::string>& name_list /Out/,
				std::vector<int>& idx_list /Out/,
				std::vector<double>& factor_list /Out/,
				std::vector<double>& min_val_list /Out/);

 protected:
	virtual void updateImageSize();

	virtual bool checkSettings(SlsDetector::Defs::Settings settings);

	virtual SlsDetector::Defs::ReadoutFlags getReadoutFlagsMask();
	virtual bool checkReadoutFlags(SlsDetector::Defs::ReadoutFlags flags,
				       std::vector<int>& flag_list,
				       bool silent = false);

	virtual int getRecvPorts();

	virtual void prepareAcq();
	virtual void processRecvFileStart(int recv_idx, unsigned int dsize);
	virtual void processRecvPort(int recv_idx, unsigned long frame, int port,
				    char *dptr, unsigned int dsize, Mutex& lock,
				    char *bptr);
};

}; // namespace SlsDetector
