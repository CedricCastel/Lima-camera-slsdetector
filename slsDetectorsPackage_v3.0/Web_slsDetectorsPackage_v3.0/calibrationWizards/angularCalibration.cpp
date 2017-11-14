#include "angularCalibration.h"
#include "fileIOStatic.h"
#include <math.h>

#include "TROOT.h"
#include "TSystem.h"
#include "TMinuit.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TList.h"
#include "TF1.h"
#include "TF2.h"
#include "TKey.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TGraphErrors.h"
#include "TRandom.h"
#include "TPostScript.h"
#include "scanStep.h"


int plotflag=0;



angularCalibration::angularCalibration(): angularConversionStatic(), plotflag(1), direction(1) {
    peakFunc= new TF1("fitpeak",this, &angularCalibration::peakfunction,-180.,180.,5); 
    angFunc = new TF1("fitangle",this, &angularCalibration::anglefunction,0.,1280.,3);
    fitList=new TList();
    fitList->SetOwner(kTRUE);
    setMoveFlag(-1,1);
    fixPars[0]=0;
    fixPars[1]=0;
    fixPars[2]=0;
    fixPars[3]=0;
    fixPars[4]=0;
    

  };
    
angularCalibration::~angularCalibration(){delete peakFunc; delete angFunc;};
    

int angularCalibration::fitModulePeak(int imod, TH1F *h1, float encoder, int chmodmin, int chmodmax, double *mypar, double *myerr) {

  printf("start fitmod imod %i encoder %f\n",imod,encoder);

  int max=-1, maxch=-1, npoints=0;
  float bg;
  float chi2;
  int ma=chmodmin, mi=chmodmax;
    
  
  
  
  float ang;
 
  angleConversionConstant *angConv=angOff+imod;

 
  printf("%f %f %f\n",angConv->getConversion(), angConv->getCenter(), angConv->getOffset());
 
  

  for (int i=chmodmin; i<chmodmax; i++) {
    ang=angle(i-chmodmin,encoder, globalOffset, angConv->getConversion(), angConv->getCenter(), angConv->getOffset(), 0, direction);
    
    if (ang>startangle && ang<stopangle) {
      if (i<mi) mi=i;
      if (i>ma) ma=i;
      if (h1->GetBinContent(i+1)> max) {
	max = (int) h1->GetBinContent(i+1);
	maxch = i;
      } 
    }
  } 
  npoints=ma-mi;
  
  cout << "Fitting between " << mi << " and " << ma <<  " " << h1 << endl;


  if (npoints<10) {
    return -1;
  }

  
  bg= (h1->Integral(mi+1,mi+10)+h1->Integral(ma-10,ma+1))/20.;


  // Creates a Root function based on function peakfunction
  peakFunc->SetRange(mi,ma);
  h1->GetXaxis()->SetRangeUser(mi,ma);
  printf("pos start parameter is %d\n",maxch);
  printf("height start parameter is %d\n",max);
  printf("bg start parameter is %f\n",bg);
  
// Sets initial values and parameter names
  peakFunc->SetParameters((Double_t) max,  (Double_t) maxch,(Double_t) 1, bg, 0);
  peakFunc->SetParNames("Constant","Mean_value","Sigma","background", "bgslope");
   
   if (plotflag) {
     cout << "plot flag 1" << endl;
     h1->Fit("fitpeak","","",mi,ma);
     h1->GetXaxis()->SetRangeUser(mi,ma);
     // h1->GetXaxis()->SetTitle("fitted!");
     h1->SetMaximum(1E5);
     h1->DrawCopy();
   } else {
     h1->Fit("fitpeak","0","",mi,ma);
     cout << "plot flag 0" << endl;
   }

   TF1 *fit = h1->GetFunction("fitpeak");


   if (fit==NULL) {
     printf("====================================peak function not fitted\n");
     return -1;
   }

// writes the fit results into the par array
   fit->GetParameters(mypar);
   
   printf("\n");
   for (int i=0;i<5;i++) {
     myerr[i] = fit->GetParError(i);     // obtain fit parameter errors
     printf("parameter %i: %f +- %f \n",i,mypar[i],myerr[i]);
   }
   
   if (mypar[1]<chmodmin || mypar[1]>chmodmax) {
     cout << "====================================Channel out of range " << mypar[1] << endl;
     return -1;
   }
   ang=angle(mypar[1]-chmodmin,encoder, globalOffset, angConv->getConversion(), angConv->getCenter(), angConv->getOffset(), 0, direction);
   if (ang<startangle || ang>stopangle) {
     cout << "====================================Channel out of range " << mypar[1] << endl;
     return -1;
   }

   if (myerr[1]> 0.1) {
     cout << "====================================Error too large " << myerr[1] << endl;
     return -1;
   }
   

   //check on Chi2??!?!?!?!?

   return 0;


}








void angularCalibration::fitCalibrationStep(TH1F *h1, double pos, int save){

  int chmin=0, chmax;
  double minang, maxang, ang;
  fitStep *st;

  Double_t mypar[5], myerr[5];
  
  cout << "Fitting!" << endl;

  for (int imod=0; imod<maxNumberOfModules; imod++) {
    chmax=chmin+chansPerMod[imod]-1;
    

    minang=angle(0,pos, globalOffset+fineOffset, angOff[imod].getConversion(), angOff[imod].getCenter(), angOff[imod].getOffset(), 0, direction);

    maxang=angle(chansPerMod[imod]-1,pos, globalOffset+fineOffset, angOff[imod].getConversion(), angOff[imod].getCenter(),  angOff[imod].getOffset(), 0, direction);
       


    //   cout << "module "<< imod << " min " << minang << " " << maxang << " " << chmin << " " << chmax << " " << chansPerMod[imod] <<  " off " << angOff[imod].getOffset() << " conv " << angOff[imod].getConversion() << " center " <<  angOff[imod].getCenter() << " dir " << direction << " totaoff " << globalOffset+fineOffset<< endl;



    if (minang>maxang) {
      ang=minang;
      minang=maxang;
      maxang=ang;
    }

    if (minang<startangle && maxang>stopangle) {
	 
      printf("fitting module %d (%f-%f) range %f-%f \t ",imod,minang, maxang, startangle, stopangle);
	 

      if (fitModulePeak(imod, h1,pos,chmin, chmax, mypar, myerr)!=-1) {

	st=new fitStep(pos,imod,mypar[1]-chmin,myerr[1]);
	if (save)
	  fitList->Add(st);

      }
    }

    chmin=chmax+1;
  }


}

TGraphErrors* angularCalibration::fitAngle(int imod, Double_t *params, Double_t *eparams) {
  TGraphErrors *gOut=new TGraphErrors();
  gOut->SetMarkerStyle(20);
  gOut->SetMarkerColor(2);
  gOut->GetXaxis()->SetTitle("Channel number");
  gOut->GetYaxis()->SetTitle("Position");
  char tit[100];
  sprintf(tit,"Module %d",imod);
  gOut->SetTitle(tit);
  
  fitStep *st=NULL;
  if (imod<0 || imod>=maxNumberOfModules)
    return NULL;

  int ip=0;

  for (int i=0; i<fitList->GetEntries(); i++) {
    st=(fitStep*)(fitList->At(i));
    if (st->module_nr==imod) {
      gOut->SetPoint(ip,st->channelfit, st->encoderfit);
      gOut->SetPointError(ip,st->channelerror, 0);
      ip++;
    }
  }
  cout << "Found " << gOut->GetN() << " for module " << imod << endl;
  TF1 *fun=fitAngle(imod,gOut);
  if (fun) {
    fun->GetParameters(params);
    params[2]=0.5*(startangle+stopangle)-params[2];//+globalOffset+fineOffset;
    for (int i=0; i<3; i++) {
      eparams[i]=fun->GetParError(i);
    }
  } else {
    for (int i=0; i<3; i++) {
      eparams[i]=-1;
      params[i]=-1;
    }
  }

  return gOut;
}


TF1* angularCalibration::fitAngle(int imod, TGraphErrors *gModule) {

  if (gModule==NULL)
    return NULL;

  if (imod<0 || imod>=maxNumberOfModules)
    return NULL;

  if (fixPars[0]==0) {
    angFunc->SetParameter(0,angOff[imod].getCenter());
    if (angOff[imod].getCenter()>=0 && angOff[imod].getCenter()<chansPerMod[imod])
      angFunc->SetParLimits(0,0,chansPerMod[imod]);
  }
  if (fixPars[1]==0) {
    angFunc->SetParameter(1,angOff[imod].getConversion());
    angFunc->SetParLimits(1,1E-10,5E-3);
  }

  if (fixPars[2]==0) {
    angFunc->SetParameter(2,0.5*(startangle+stopangle)-angOff[imod].getOffset());
    if (startangle-angOff[imod].getOffset()<stopangle-angOff[imod].getOffset())
      angFunc->SetParLimits(2,startangle-angOff[imod].getOffset(),stopangle-angOff[imod].getOffset());
    else
      angFunc->SetParLimits(2,stopangle-angOff[imod].getOffset(),startangle-angOff[imod].getOffset());
  }

//angFunc->SetParameters(angOff[imod].getCenter(),angOff[imod].getConversion(),0.5*(startangle+stopangle)-angOff[imod].getOffset());

  Double_t pmin, pmax;
  

  cout << "Start parameters :" << endl;
  angFunc->GetParLimits(0,pmin,pmax);
  cout << 0 << " " << angFunc->GetParameter(0) << " " << pmin << " " << pmax << endl;
  angFunc->GetParLimits(1,pmin,pmax);
  cout << 1 << " " << angFunc->GetParameter(1) << " " << pmin << " " << pmax << endl;
  angFunc->GetParLimits(2,pmin,pmax);
  cout << 2 << " " << angFunc->GetParameter(2) << " " << pmin << " " << pmax << endl;

  gModule->Fit("fitangle");

  cout << "fStatus " << gMinuit->fStatus << endl;
  cout << "fCstatu " << gMinuit->fCstatu << endl;

  int ifit=0;
  while ((gMinuit->fCstatu).Contains("FAILED") && ifit<10) {
    cout << "Refitting" << endl;
    gModule->Fit("fitangle");
    ifit++;
  }

  TF1 *fitfun=gModule->GetFunction("fitangle");
  if (fitfun==NULL) {
    cout << "First fit failed for module " << imod << endl;
    return NULL;
  }

  if ((gMinuit->fCstatu).Contains("FAILED"))
    return fitfun;


  int np=gModule->GetN();

  Double_t x,y;

  for (int ip=np-1; ip>=0; ip--) {
    gModule->GetPoint(ip,x,y);
    if (fabs(y-fitfun->Eval(x))>0.01) {
      cout << "Step " << y << " distance " << (y-fitfun->Eval(x)) << "("<< y << " " << fitfun->Eval(x) << ")"<< endl;
      gModule->RemovePoint(ip);
    }
  }
  
  cout << "Module " << imod << " removed " << np-gModule->GetN() << " points " << endl;

  

  if (gModule->GetN()<5) {
    cout << "Removed too many points for module "<< imod << endl;
    return NULL;
  }

  if (gModule->GetN()==np) {
    cout << "All points were good - did not need to discard any for module "<< imod << endl;
    return fitfun;
  }

  gModule->Fit("fitangle"); 
  ifit=0;
  while ((gMinuit->fCstatu).Contains("FAILED")  && ifit<10) {
    cout << "Refitting" << endl;
    gModule->Fit("fitangle");
    ifit++;
  }
  fitfun=gModule->GetFunction("fitangle");
  if (fitfun==NULL) {
    cout << "Second fit failed for module " << imod << endl;
    return NULL;
  }
  
  return fitfun;
  

}

int angularCalibration::fitSteps(TList *stepList){
  
  if (stepList==NULL) {
    return -1;
  }
  scanStep *st;
  
  int nsteps=stepList->GetEntries();
  
  int totch=0;
  for (int i=0; i<maxNumberOfModules; i++)
    totch+=chansPerMod[i];
  
  double *data=new double[totch];
  double *chans=new double[totch];

  int nch=-1;
  TH1F *hrun=new TH1F("hrun","step",totch,-0.5,totch-0.5);


  for (int is=0; is<nsteps; is++) {
    hrun->Reset();
    st=(scanStep*)stepList->At(is);
    nch=fileIOStatic::readDataFile(totch, st->getFileName(), data, NULL, chans);
    for (int ich=0; ich<nch; ich++)
      hrun->Fill(chans[ich],data[ich]);
    hrun->SetTitle(st->getFileName().c_str());
    hrun->Sumw2();
    
    fitCalibrationStep(hrun,st->getValue());
    
  }
  
  return 0;

}
