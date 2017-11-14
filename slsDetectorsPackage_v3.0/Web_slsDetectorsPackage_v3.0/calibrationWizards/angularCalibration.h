#ifndef ANGULAR_CALIBRATION_H
#define ANGULAR_CALIBRATION_H

#include "angularConversionStatic.h"
#include <TMath.h>
#include <TList.h>
#include <TF1.h>
#include "angleConversionConstant.h"
#include "sls_detector_defs.h"








class TH1F;
class TGraphErrors;


class angularCalibration   : virtual public angularConversionStatic {
  
 public:
  
  
  angularCalibration();
    
  ~angularCalibration();
    


  int setDirection(int d=0) {if (d>0) direction=1; if (d<0) direction=-1; return direction;};


  int setFitRange(double min, double max){startangle=min; stopangle=max;};

  double setFineOffset(double fo){fineOffset=fo; return fineOffset;};
  double getFineOffset(){return fineOffset;};
  
  double setGlobalOffset(double fo){globalOffset=fo; return globalOffset;};
  double getGlobalOffset(){return globalOffset;};
  
  int setChansPerMod(int imod=-1, int ch=-1){	\
    cout << "Set chans " << ch << " for module " << imod << endl;	\
    if (ch>=0) {				\
      if (imod>=0 && imod<MAXDET*MAXMODS) chansPerMod[imod]=ch;	\
      else if (imod==-1) for (int im=0; im<MAXDET*MAXMODS; im++)  chansPerMod[im]=ch;	\
    }									\
    if (imod>=0 && imod<MAXDET*MAXMODS)      return chansPerMod[imod];	\
    int nch=-100;							\
    for (int im=0; im<MAXDET*MAXMODS; im++)				\
      if (chansPerMod[im]!=nch && nch!=-100)	nch=-1;	      else    	nch=chansPerMod[im];					\
   	cout << "return " << nch << endl;	 return nch;			};
  


  int setAngularConversionConstants(string fname){return  readAngularConversion(fname, maxNumberOfModules, angOff);};


  angleConversionConstant *setAngularConversionConstants(int imod,  angleConversionConstant *acf) {\
    int maxmod=0, minmod=0;						\
    if (imod<0) {							\
      maxmod=MAXDET*MAXMODS;						\
      minmod=0;								\
    }  else {								\
      minmod=imod;							\
      maxmod=imod+1;							\
    }									\
    for (int im=minmod; im<maxmod; im++)      angOff[im].setAngConvConstant(acf); \
    if (imod>=0 && imod<MAXDET*MAXMODS)      return angOff+imod;	\
    return NULL;  }

  
  int setMoveFlag(int imod=-1, int ch=-1){			\
    if (ch>=0) {						\
      if (imod>=0 && imod<MAXDET*MAXMODS) moveFlag[imod]=ch;	\
      else if (imod==-1) for (int im=0; im<MAXDET*MAXMODS; im++)  moveFlag[im]=ch;	\
    }									\
    if (imod>=0 && imod<MAXDET*MAXMODS)      return moveFlag[imod];	\
    int nch=-100;							\
    for (int im=0; im<MAXDET*MAXMODS; im++)				\
      if (moveFlag[im]!=nch && nch!=-100)	nch=-1;			\
      else    	nch=moveFlag[im];					\
    return nch;								};


  int setTotalNumberOfChannels(int d=-1) {if (d>=0) totalNumberOfChannels=d;  return totalNumberOfChannels;};
  int setNumberOfModules(int d=-1) {if (d>=0 && d<=maxNumberOfModules) numberOfModules=d;  return numberOfModules;};
  int setMaxNumberOfModules(int d=-1) {if (d>=0) maxNumberOfModules=d;  return maxNumberOfModules;};
  
  
  int setPlotFlag(int i=-1){if (i>=0) plotflag=i; return plotflag;};

  void fitCalibrationStep(TH1F *hrun, double pos, int save=1);

  TGraphErrors* fitAngle(int imod, Double_t *par, Double_t *epar);

  void resetFit(){fitList->Clear();};

  void fixParameter(int ipar, double val){angFunc->FixParameter(ipar,val);fixPars[ipar]=1;};
  void releaseParameter(int ipar){angFunc->ReleaseParameter(ipar);fixPars[ipar]=0;};
  


 private:


  Double_t peakfunction(Double_t *x, Double_t *par) {	      \
    Double_t arg = 0;					      \
    if (par[2] != 0) arg = (x[0] - par[1])/par[2];	      \
    return par[0]*TMath::Exp(-0.5*arg*arg)+par[3]-par[4]*arg; \
  };
  
  
  Double_t anglefunction(Double_t *x, Double_t *par) {		\
    return par[2]-angle(x[0],0,globalOffset+fineOffset,par[1],par[0],0,0,direction);\
  };
  

  int plotflag;

  TList *fitList;
  
  
  TF1 *peakFunc;
  TF1 *angFunc;
  

  double startangle, stopangle;


  int direction;
  double fineOffset;
  double globalOffset;
  int chansPerMod[MAXDET*MAXMODS];
  angleConversionConstant angOff[MAXDET*MAXMODS];
  int moveFlag[MAXDET*MAXMODS];
  int moduleMask[MAXDET*MAXMODS];
  int totalNumberOfChannels;
  int numberOfModules;
  int maxNumberOfModules;
  int badChanMask[MAXDET*MAXMODS*65535];// use it when creating the histogram!

  int fixPars[5];
  
  int fitModulePeak(int imod, TH1F *h1,  float encoder, int chmin, int chmax, double *mypar, double *myerr);

  TF1* fitAngle(int imod, TGraphErrors *gModule);

  int fitSteps(TList *stepList);

};

class fitStep:  public TObject {

 public:
  fitStep(Double_t pos, Int_t mod, Double_t chan, Double_t echan):encoderfit(pos), module_nr(mod), channelfit(chan), channelerror(echan){};
  Double_t encoderfit;
  Int_t module_nr;
  Double_t channelfit;
  Double_t channelerror;
  
  
   ClassDef(fitStep,0)
};


#endif
