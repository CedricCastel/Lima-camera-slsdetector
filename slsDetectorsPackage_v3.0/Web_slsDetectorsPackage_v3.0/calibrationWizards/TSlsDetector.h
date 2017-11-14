#ifndef T_SLS_DETECTOR_H
#define T_SLS_DETECTOR_H



class TH1F;
class TH2F;
class TList;
class TGraphErrors;
class angleConversionConstant;
#include <string>

using namespace std;

class TSlsDetector {


 public:

  static void rootLogon();
  static TH1F* dataFileHistogram(int nch, string fname, int ef=0);
  static TH2F* dataScanHistogram(int nch, TList *l, int ef=0);
  static TGraphErrors* dataFileGraph(int nch,string fname, int ef=0);
  static void normalizeFF(TH1F* hff);
  static void ffCorrect(TH1F* hdata, TH1F* hff);
  static void  discardBadChannels(TH1F *hdata, int nbad, int *badlist);
  static void processData(TH1F *hdata, TH1F *hff, int nbad, int *badlist);
  static TGraphErrors *convertAngles(TH1F *hdata, double pos, int *chansPerMod, angleConversionConstant **angOff, int *mF, double fo, double go, int angdir, int nbad, int *badlist);
  
};


#endif
