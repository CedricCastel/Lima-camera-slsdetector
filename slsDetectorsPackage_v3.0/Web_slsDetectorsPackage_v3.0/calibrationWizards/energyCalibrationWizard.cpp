#include <TApplication.h>
#include <TColor.h>

#include <TStyle.h>
#include <TROOT.h>

#include "enCalWizard.h"

void example() {
   // Popup the GUI...
   enCalWizard *mf=new enCalWizard(gClient->GetRoot(),800,800);
   mf->addEnergyPage();
   mf->moduleCalibrationPage();
   mf->changePage(-1);
}

int main(int argc, char **argv) {
   TApplication theApp("App",&argc,argv);


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
  gStyle->SetPadTopMargin(0.15);
  gStyle->SetPadRightMargin(0.15);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetLegendBorderSize(1);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameFillColor(kWhite);
  // gStyle->SetLegendFillColor(kWhite);
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

  example();


   theApp.Run();
   return 0;
}
