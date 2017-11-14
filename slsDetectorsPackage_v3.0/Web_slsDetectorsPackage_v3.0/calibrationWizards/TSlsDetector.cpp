#include "TSlsDetector.h"
#include "fileIOStatic.h"
#include "scanStep.h"
#include "angularConversionStatic.h"

#include <TH1F.h>
#include <TH2F.h>
#include <TMath.h>
#include <TGraphErrors.h>
#include <TMath.h>
#include <TColor.h>
#include <TStyle.h>
#include <TROOT.h>
#include <TApplication.h>



void TSlsDetector::rootLogon(){
 gStyle->SetDrawBorder(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetCanvasDefH(800);
  gStyle->SetCanvasDefW(800);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetPaintTextFormat("5.2f");
  gStyle->SetLineWidth(2);
  gStyle->SetTextSize(1.1);
  gStyle->SetLabelSize(0.04,"xy");
  gStyle->SetTitleSize(0.05,"xy");
  gStyle->SetTitleOffset(1.0,"x");
  gStyle->SetTitleOffset(1.1,"y");
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadRightMargin(0.1);
  gStyle->SetPadBottomMargin(0.1);
  gStyle->SetPadLeftMargin(0.1);
  gStyle->SetLegendBorderSize(1);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetFillColor(kWhite);
  gStyle->SetStatFontSize(0.03);
  gStyle->SetStatBorderSize(1);
  gStyle->SetStatFormat("6.4g");
  gStyle->SetStatX(0.95);
  gStyle->SetStatY(0.95);
  gStyle->SetStatW(0.2);
  gStyle->SetStatH(0.2);
  gStyle->SetTitleX(0.1);
  gStyle->SetTitleY(0.95);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleFontSize(0.05);
  gROOT->SetStyle("Default");


  TColor::InitializeColors();
  const Int_t NRGBs = 5;
  const Int_t NCont = 90;

  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);


  gROOT->ForceStyle();
}

TH2F* TSlsDetector::dataScanHistogram(int nch, TList *l, int ef) {
  

  scanStep *s=NULL;
  double minval=1E7, maxval=-1E7;
  double val;
  
  double *data=new double[nch];
  double *ang=new double[nch];
  double*err=NULL;
  if (ef)
    err=new double[nch];


  if (l==NULL)
    return NULL;
  if (l->GetEntries()<2)
    return NULL;
    

  for (int id=0; id<l->GetEntries(); id++) {
    s=(scanStep*)l->At(id);
    if (s) {
      val=s->getValue();
      if (id==0) {
	minval=val;
	maxval=val;
      }
      if (val<minval)
	minval=val;
      if (val>maxval)
	maxval=val;
    }
  }
  double step=(maxval-minval)/l->GetEntries();



  TH2F *h2=new TH2F("scan","scan",nch,-0.5,nch-0.5,l->GetEntries(),minval-0.5*step,maxval+0.5*step);

  while (h2->GetNbinsY()>500)
    h2->RebinY();

  while (h2->GetNbinsX()>10000)
    h2->RebinX();


  int np;

  int ibin;
  
  for (int id=0; id<l->GetEntries(); id++) {
    s=(scanStep*)l->At(id);
    if (s) {
      cout << "reading file " <<  s->getFileName() << endl;

      np=fileIOStatic::readDataFile(nch,s->getFileName(),data,err,ang);
   
      
      for (int i=0; i<np; i++) {
	ibin=h2->FindBin(ang[i],s->getValue());
	if (data[i]>=0)
	  h2->SetBinContent(ibin,data[i]);
	if (err)
	  h2->SetBinError(ibin,err[i]);
      }
    }
  }

  if (err==NULL)
    h2->Sumw2();


  delete [] data;
  delete [] ang;
  if (err)
    delete [] err;
  
  return h2;
  

}

TH1F* TSlsDetector::dataFileHistogram(int nch, string fname, int ef) {
  double *data=new double[nch];
  double *ang=new double[nch];
  double*err=NULL;
  if (ef)
    err=new double[nch];


  TH1F *h1=new TH1F("h1",fname.c_str(),nch, -0.5,nch);


  int np=fileIOStatic::readDataFile(nch,fname,data,err,ang);
 
 
  int ch;
  for (int i=0; i<np; i++) {
    ch=ang[i];
    if (data[i]>=0)
      h1->SetBinContent(ch+1,data[i]);
    if (err)
      h1->SetBinError(ch+1,err[i]);
  }
  if (err==NULL)
    h1->Sumw2();


  delete [] data;
  delete [] ang;
  if (err)
    delete [] err;
  
  return h1;

}



TGraphErrors* TSlsDetector::dataFileGraph(int nch, string fname, int ef) {
  double *data=new double[nch];
  double *ang=new double[nch];
  double *err=NULL;
  if (ef)
    err=new double[nch];
  


  int np=fileIOStatic::readDataFile(nch,fname,data,err,ang);
  if (err==NULL) {
    err=new double[nch];
    for (int i=0; i<np; i++) {
      if (data[i]>0)
	err[i]=TMath::Sqrt(data[i]);
    }
  }


  TGraphErrors *g=new TGraphErrors(np,ang,data,NULL,err);
 
  delete [] data;
  delete [] ang;
  if (err)
    delete [] err;
  
  return g;

}
void TSlsDetector::normalizeFF(TH1F* hff) {

  if (hff==NULL)
    return;
  
  int np=0;
  for (int ib=0; ib<hff->GetNbinsX()+1; ib++) {
    if (hff->GetBinContent(ib+1)>0)
      np++;
  }


  Double_t me=hff->Integral()/(double)np;

  hff->Scale(1./me);
}

void TSlsDetector::ffCorrect(TH1F* hdata, TH1F* hff){
  if (hff==NULL || hdata==NULL)
    return;


  TH1F *h1=hdata;

  for (int ib=1; ib<=hff->GetNbinsX(); ib++)
    if (hff->GetBinContent(ib)==0) hff->SetBinContent(ib,1); 


  h1->Divide(hff);



}

void  TSlsDetector::discardBadChannels(TH1F *hdata, int nbad, int *badlist) {
  if (badlist==NULL || hdata==NULL)
    return;

  
 TH1F *h1=hdata;
 
 for (int ich=0; ich<nbad; ich++) {
   h1->SetBinContent(badlist[ich]+1,0);
   h1->SetBinError(badlist[ich]+1,1E7);
 }


}
void TSlsDetector::processData(TH1F *hdata, TH1F *hff, int nbad, int *badlist){
 
  TH1F *h1=hdata;

  if (badlist) {
    discardBadChannels(hdata,nbad,badlist);
    if (hff)
      discardBadChannels(hff,nbad,badlist);
  }
  
  if (hff) {
    ffCorrect(hdata, hff);
  }


}


TGraphErrors* TSlsDetector::convertAngles(TH1F *hdata, double pos, int *chansPerMod, angleConversionConstant **angOff, int *mF, double fo, double go, int angdir, int nbad, int *badlist) {

  if (angOff==NULL || hdata==NULL)
    return NULL;

  angularConversionStatic ac;
  
  double *ang=ac.convertAngles(pos, hdata->GetNbinsX(), chansPerMod, angOff, mF, fo, go, angdir);

  if (ang==NULL)
    return NULL;

  TGraphErrors *g=new TGraphErrors();

  int ipoint=0;

  for (int ich=0; ich<hdata->GetNbinsX(); ich++) {
    
    if (badlist) {
      for (int ib=0; ib<nbad; ib++)
	if (ib==ich) continue;
    }
    
    g->SetPoint(ipoint,ang[ich],hdata->GetBinContent(ich+1));
    g->SetPointError(ipoint,0,hdata->GetBinError(ich+1));
    ipoint++;

  }


  return g;
}
