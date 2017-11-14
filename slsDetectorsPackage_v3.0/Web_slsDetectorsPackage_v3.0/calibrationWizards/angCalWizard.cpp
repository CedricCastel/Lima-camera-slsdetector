#include <TApplication.h>
#include <TGClient.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TRandom.h>
#include <TGButton.h>
#include <TRootEmbeddedCanvas.h>
#include <TGButtonGroup.h>
#include <TGNumberEntry.h>
#include <TGLabel.h>
#include <TList.h>
#include <TGFileDialog.h>
//#include <TGLBContainer.h>
#include <TGComboBox.h>
#include <TH2F.h>
#include <TColor.h>
#include <TH1F.h>
#include <TGraphErrors.h>
#include <THStack.h>
#include "angCalLogClass.h"
#include "scanStep.h"
#include "fileIOStatic.h"


#include <stdio.h>
#include <iostream>
#include <fstream>

#include "angleConversionConstant.h"
#include "angCalWizard.h"
#include "badChannelCorrections.h"
#include "angularConversionStatic.h"
#include "TSlsDetector.h"
using namespace std;



#define DEFAULTFN "run.angcal"


angCalWizard::angCalWizard(const TGWindow *p,UInt_t w,UInt_t h, char *s) :	\
  calFile(s),
  TGMainFrame(p,w,h), 
  fScanCanvas(NULL),
  fModulecanvas(NULL),
  advancementBG(NULL),
  vframe(NULL),
  page(NULL),
  angCalFileEntry(NULL),
  outFileEntry(NULL),
  angMinEntry(NULL),
  angMaxEntry(NULL),
  angCalFileBG(NULL),
  stepList(NULL),
  stepListBG(NULL),
  nModLabel(NULL),
  maxModLabel(NULL),
  chansPerModLabel(NULL),
  angConvFileEntry(NULL),
  badChanFileEntry(NULL),
  ffFileEntry(NULL),
  angDirCB(NULL),
  totalOffEntry(NULL),
  stepFitBG(NULL),
  centerEntry(NULL),
  conversionEntry(NULL),
  offsetEntry(NULL),
  centerLabel(NULL),
  conversionLabel(NULL),
  offsetLabel(NULL),
  moduleFitBG(NULL),
  numberOfModules(-1),
  channelsPerModule(-1),
  hsSteps(NULL),
  ffH1(NULL),
  previewH1(NULL),
  processedH1(NULL),
  scanH2(NULL),
  gStep(NULL),
  gModule(NULL),
  error(0),
  goodData(1),
  scanList(NULL),
  scan1Frame(NULL),
  moduleCalibrationFrame(NULL),
  myAngCal(NULL), angOff(NULL), fitAngOff(NULL), fitted(NULL), badChannelsList(NULL), nBad(0), iModule(0) {


  myDir=string("./");

  hsSteps=new THStack();


  scanList=new TList();

  myAngCal=new angularCalibration();

  vframe=new TGVerticalFrame(this, 800,1200);

  hpage=new TGHorizontalFrame(vframe, 800,1200);
  page=new TGVerticalFrame(hpage, 1500,1200);


  advancementBG=new TGButtonGroup(vframe,"",kHorizontalFrame);


  TGTextButton *goToCalibrationButton = new TGTextButton( advancementBG,"&Proceed to Modules Calibration");
  goToCalibrationButton->MapWindow();
  TGTextButton *finishedButton = new TGTextButton( advancementBG,"&Write angular calibration file ");
 finishedButton->MapWindow();
  finishedButton->SetEnabled(kFALSE);
  TGTextButton *exitButton = new TGTextButton( advancementBG,"&Exit ");
  exitButton->MapWindow();
  // hframe->AddFrame(exit, new TGLayoutHints(kLHintsRight,1,1,3,4));


  vframe->AddFrame(hpage,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5,5,5,1));
  
  vframe->AddFrame(advancementBG,new TGLayoutHints(kLHintsExpandX, 5,5,5,1));
  //new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
 
  hpage->AddFrame(page,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 10,10,10,1));

  AddFrame(vframe,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5,5,5,1));
  advancementBG->Connect("Clicked(Int_t)","angCalWizard",this,"changePage(Int_t)");

  // changePage(-1);

  vframe->MapWindow();
  // hframe->MapWindow();
  advancementBG->MapWindow();
   // Sets window name and shows the main frame
  SetWindowName("Energy Calibration");
  MapSubwindows();
  // Resize(GetDefaultSize());
  MapWindow();
  Resize(800,1000);

  addScanPage();
  moduleCalibrationPage(); 
  addOutFilePage(); 

  page->HideFrame(moduleCalibrationFrame);
  hpage->HideFrame(fModulecanvas);
  page->HideFrame(outFileFrame);

  page->MapWindow();

};

//   energyList=new TList();
//   strcpy(detectorSettings,"none");
//   strcpy(modulesSerialNumbers,"none");
//   previewH1=new THStack();
//   previewGraph=new TGraphErrors();
//   previewGraph->SetMarkerStyle(20);
  

//   // TGHorizontalFrame *hframe=new TGHorizontalFrame(vframe, 800,100);
//   advancementBG=new TGButtonGroup(vframe,"",kHorizontalFrame);

 
//   for (int i=0; i<100; i++) {
//     h1Modules[i]=NULL;
//     fileSaved[i]=0;
//   }


// }





// void angCalWizard::selectEnergy(Int_t i){
//   editEnergyList(-1); 
//   energyH2=(TH2F*)energyList->At(energyListCombo->GetSelected()-1); 
//   cout << "selected " << energyListCombo->GetSelected() << endl;
//   if (energyH2)
//     cout << "Histogram is " << energyH2->GetTitle() << endl;
//   else
//     cout << "No histogram in list!" << endl;


// }



void angCalWizard::editStepList(Int_t i) {


  switch (i) {
  case -1:
    break;
  case 1:
    previewStep();

    cout << "Preview selected step"<< endl;
    break;
  case 2:
    cout << "Remove selected step"<< endl;
    removeStep();
    break;
  case 3:
    cout << "Fit selected step"<< endl;
    fitStep();
    break;
  default:
    cout << "Unknown button "<< i << endl;
  }


  
}

void angCalWizard::loadAngCalFile() {

  scanStep *s;

  goodData=0;
  error=0;

  ifstream infile(angCalFileEntry->GetText());
   double enc;
   char fn[10000];
   double angmin=360, angmax=-360;

  int c=string::npos;

  if (infile.is_open()) {
    cout << "Opened file " << angCalFileEntry->GetText() << endl;
    c=string(angCalFileEntry->GetText()).rfind('/');

    if (c!=string::npos)
      myDir=string(angCalFileEntry->GetText()).substr(0,c+1);
    
    //    cout << "Working directory is " << myDir << endl;

    angCalLogClass ac; 
    char text[1000];
    int nmod=-1, chanspermod=-1, maxmod=-1, angdir=0;
    double globaloff, fineoff;
    char angconvfile[10000], ffdir[10000], fffile[10000], badfile[10000];
    int istep=0;
    ac.readHeader(infile, maxmod, nmod, chanspermod, angconvfile, globaloff, fineoff, angdir, ffdir, fffile, badfile );
    TGLBEntry *l;

    while (ac.getStep(infile, enc,fn)>=0) {
      
      s=new scanStep(enc, fn);
      if (enc<angmin) angmin=enc;
       if (enc>angmax) angmax=enc;
      

       scanList->Add(s);

    }
    infile.close();
    scanList->Sort();

    for (int is=0; is<scanList->GetEntries(); is++) {
      s=(scanStep*)scanList->At(is);
      stepList->AddEntry((s->Print()).c_str(), is );
      cout << "Added " << s->Print() << endl;
      //       //delete s;
      istep++; 
    }
    stepList->Select(0);



    sprintf(text,"Number of modules %d",nmod);
    nModLabel->SetText(text);
    numberOfModules=nmod;
    if (numberOfModules<=0)
      error=1;
    else
      myAngCal->setNumberOfModules(numberOfModules);

    sprintf(text,"Channels per Module %d",chanspermod);
    chansPerModLabel->SetText(text);

    channelsPerModule=chanspermod;
    if (channelsPerModule<=0)
      error=1;
    else
      myAngCal->setChansPerMod(-1,channelsPerModule);

    sprintf(text,"Maximum number of modules %d",maxmod);
    cout << text << endl;
    maxModLabel->SetText(text);
    maxNumberOfModules=maxmod;
    if (maxNumberOfModules<=0)
      error=1;
    else
      myAngCal->setMaxNumberOfModules(maxNumberOfModules);
    
    cout << "tot number of chans" << endl;
    myAngCal->setTotalNumberOfChannels(numberOfModules*channelsPerModule);
    
    
    cout << "angconv" << endl;
    angConvFileEntry->SetText(angconvfile);
    readAngularConversion();


    cout << "badchans" << endl;
    badChanFileEntry->SetText(badfile);
    readBadChans();

    cout << "ff" << endl;
    ffFileEntry->SetText((string(ffdir)+string("/")+string(fffile)).c_str());
    readFlatField();


    totalOffEntry->SetNumber(globaloff+fineoff);
    myAngCal->setFineOffset(0);
    myAngCal->setGlobalOffset(globaloff+fineoff);
    


    if (angdir<0) 
      angDirCB->SetDown(kTRUE);
    else
      angDirCB->SetDown(kFALSE);
    myAngCal->setDirection(angdir);

    if (angdir==0)
      error=1;
    

    if (error==1)
      cout << "Error in angcal file!" << endl;
    
    goodData=1;
    
    previewSteps();

    setPlotMode(6);

    
  } else
    cout << "Could not open file " << angCalFileEntry->GetText() << endl;
  
  

}







void angCalWizard::removeStep() {

  int id=stepList->GetSelected();
  scanStep *s=(scanStep*)scanList->At(id);

  if (s) {
    stepList->RemoveEntries(id,stepList->GetNumberOfEntries());
    scanList->Remove(s);
  }

  for (int i=id-1; i<scanList->GetEntries(); i++) {
    stepList->AddEntry(((scanStep*)scanList->At(i))->Print().c_str(),i+1);
  }
  if (id>0)
    stepList->Select(id-1);
  else
    stepList->Select(id);
    
  changePage(-1);
  
  cout << "Remove step " << endl;
}







void angCalWizard::changePage(Int_t i) {
  cout << "Changing page " << i << endl;

    scanStep *s=NULL;
   switch (i) {
  case -1:
    break;
  case 1:
    //proceed to module calibration
    myAngCal->setPlotFlag(0);
    myAngCal->resetFit();
    for (int is=0; is<scanList->GetEntries(); is++) {
      s=(scanStep*)(scanList->At(is));
      fitStep(s,1);
    }
    hpage->HideFrame(fScanCanvas);
    page->HideFrame(scan1Frame);
    hpage->ShowFrame(fModulecanvas);
    page->ShowFrame(moduleCalibrationFrame);
    scrollModule(-1);
    // ((TGTextButton*)moduleFitBG->GetButton(1))->SetEnabled(kFALSE);
    break;
  case 2:
    hpage->HideFrame(fModulecanvas);
    page->HideFrame(moduleCalibrationFrame);
    page->ShowFrame(outFileFrame);
    break;
  case 3:
    cout << "Exit root!"<< endl;
    gApplication->Terminate(0);
    break;
    
  default:
    cout << "Unknown button "<< i << endl;
  }

}


void  angCalWizard::scrollModule(Int_t ib) {

  int changed=0;
  char tmp[100];

  switch (ib) {
  case -1:
    changed=1;
    break;

  case 1:
    cout << "Moving to previous module " ;
    if (iModule>0)
      iModule--;
    changed=1;
    cout << iModule << endl;
    break;
    
  case 3:
    cout << "Moving to next module " ;
    if (iModule<(numberOfModules-1))
      iModule++;
    changed=1;
    cout << iModule << endl;
    break;
   
  default:
    cout << "Module number is " << iModule << endl;
  
  }

  int imod=iModule;

  if (changed) {
    sprintf(tmp,"Module %d",iModule);
    
    ((TGTextButton*)moduleFitBG->GetButton(2))->SetText(tmp);
    
    centerEntry->SetNumber((angOff+imod)->center);
    conversionEntry->SetNumber((angOff+imod)->r_conversion);
    offsetEntry->SetNumber((angOff+imod)->offset);
    
    if (iModule>0)
      moduleFitBG->GetButton(1)->SetEnabled(kTRUE);
    else
      moduleFitBG->GetButton(1)->SetEnabled(kFALSE);
    
    
  
    if (iModule<(numberOfModules-1))
      moduleFitBG->GetButton(3)->SetEnabled(kTRUE);
    else
      moduleFitBG->GetButton(3)->SetEnabled(kFALSE);
  }
  moduleNumberChanged();

}


void angCalWizard::moduleNumberChanged() {

  char tmp[100];

  int imod=iModule;

  if (gModule)
    delete gModule;

  Double_t params[3], eparams[3];

  
  if (centerCB->IsDown())
    myAngCal->fixParameter(0,centerEntry->GetNumber());
  else
    myAngCal->releaseParameter(0);
    
  if (conversionCB->IsDown())
    myAngCal->fixParameter(1,conversionEntry->GetNumber());
  else
    myAngCal->releaseParameter(1);
    

  if (offsetCB->IsDown())
    myAngCal->fixParameter(2,0.5*(angMinEntry->GetNumber()+angMaxEntry->GetNumber())-offsetEntry->GetNumber());
  else
    myAngCal->releaseParameter(2);
    

  gModule=myAngCal->fitAngle(imod,params,eparams);

  (fitAngOff+imod)->center=params[0];
  (fitAngOff+imod)->ecenter=eparams[0];
  (fitAngOff+imod)->r_conversion=params[1];
  (fitAngOff+imod)->er_conversion=eparams[1];
  (fitAngOff+imod)->offset=params[2];
  (fitAngOff+imod)->eoffset=eparams[2];

  sprintf(tmp,"%f +- %f",params[0],eparams[0]);
  centerLabel->SetText(tmp);

  sprintf(tmp,"%f +- %f E-05",params[1]*1E5,eparams[1]*1E5);
  conversionLabel->SetText(tmp);

  sprintf(tmp,"%f +- %f",params[2],eparams[2]);
  offsetLabel->SetText(tmp);

  if (gModule)
    ((TGTextButton*)moduleFitBG->GetButton(2))->SetText(gModule->GetTitle());
  


  TCanvas *fCanvas = fModulecanvas->GetCanvas();
  fCanvas->cd();
  gModule->Draw("AP");

  cout << "Drawing?" << endl;
  fCanvas->Update();
  fitted[imod]=1;

  ((TGTextButton*)advancementBG->GetButton(2))->SetEnabled(kTRUE);
  
  for (int i=0; i<numberOfModules; i++) {
    if (fitted[i]==0)
      ((TGTextButton*)advancementBG->GetButton(2))->SetEnabled(kFALSE);
  }

}















  




















void angCalWizard::addOutFilePage() {
  TGHorizontalFrame *hframe;
  TGLabel *label;
 
  outFileFrame = new TGGroupFrame(page,"",kVerticalFrame);
  page->AddFrame(outFileFrame,new TGLayoutHints( kLHintsTop | kLHintsExpandX , 0,0,0,0));
  outFileFrame->MapWindow();
  



  hframe=new TGHorizontalFrame(outFileFrame, 800,30);
  outFileFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
  
  
  label = new TGLabel(hframe, "Angular Conversion file:");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
  label->Resize(200,30);



  outFileEntry=new TGTextEntry(hframe, "ang_new.off",1);
  hframe->AddFrame(outFileEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX, 0, 1, 0, 1));
  outFileEntry->MapWindow();
  outFileEntry->Resize(200,30);

  TGTextButton *browse = new TGTextButton( hframe,"&Browse ");
  hframe->AddFrame(browse,new TGLayoutHints(kLHintsTop | kLHintsLeft , 0, 1, 0, 1));
  browse->MapWindow();
  browse->Resize(100,30);

  browse->Connect("Clicked()","angCalWizard",this,"outFileDialog()");

  
  TGTextButton *button = new TGTextButton(hframe,"&Save ");
  hframe->AddFrame(button,new TGLayoutHints(kLHintsTop | kLHintsLeft , 0, 1, 0, 1));
  button->MapWindow();
  button->Resize(100,30);

  button->Connect("Clicked()","angCalWizard",this,"saveAngConvFile()");
}







void angCalWizard::addScanPage() {
  TGHorizontalFrame *hframe;
  TGLabel *label;
 
  scan1Frame = new TGGroupFrame(page,"",kVerticalFrame);
  page->AddFrame(scan1Frame,new TGLayoutHints( kLHintsTop | kLHintsExpandX , 0,0,0,0));
  scan1Frame->MapWindow();
  

  TGGroupFrame *scanFrame = new TGGroupFrame(scan1Frame,"Angular Calibration",kVerticalFrame);
  scanFrame->SetTitlePos(TGGroupFrame::kLeft);
  scan1Frame->AddFrame(scanFrame,new TGLayoutHints( kLHintsTop | kLHintsExpandX , 5,5,5,5));
  scanFrame->MapWindow();
  
  



  hframe=new TGHorizontalFrame(scanFrame, 800,30);
  scanFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
  
  
  label = new TGLabel(hframe, "Angular Calibration File Log:");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
  label->Resize(200,30);


  if (calFile==NULL)
    angCalFileEntry=new TGTextEntry(hframe, DEFAULTFN,1);
  else
    angCalFileEntry=new TGTextEntry(hframe,calFile,1);
    
  hframe->AddFrame(angCalFileEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX, 0, 1, 0, 1));
  angCalFileEntry->MapWindow();
  angCalFileEntry->Resize(200,30);

  TGTextButton *browse = new TGTextButton( hframe,"&Browse ");
  hframe->AddFrame(browse,new TGLayoutHints(kLHintsTop | kLHintsLeft , 0, 1, 0, 1));
  browse->MapWindow();
  browse->Resize(100,30);

  browse->Connect("Clicked()","angCalWizard",this,"angCalFileDialog()");

  
  TGTextButton *button = new TGTextButton(hframe,"&Load ");
  hframe->AddFrame(button,new TGLayoutHints(kLHintsTop | kLHintsLeft , 0, 1, 0, 1));
  button->MapWindow();
  button->Resize(100,30);

  button->Connect("Clicked()","angCalWizard",this,"loadAngCalFile()");







  scanFrame = new TGGroupFrame(scan1Frame,"Angular Calibration Summary",kVerticalFrame);
  scanFrame->SetTitlePos(TGGroupFrame::kLeft);
  scan1Frame->AddFrame(scanFrame,new TGLayoutHints( kLHintsTop | kLHintsExpandX , 5,5,5,5));
  scanFrame->MapWindow();
  
  

  hframe=new TGHorizontalFrame(scanFrame, 800,30);
  scanFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
  
  label = new TGLabel(hframe, "Angular Calibration Steps:");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  
  // stepList=new TGListBox(hframe,110);
  stepList=new TGComboBox(hframe,110);
  // stepList->SetMultipleSelections(kTRUE);
  stepList->Resize(150,30);
  hframe->AddFrame(stepList,new TGLayoutHints(kLHintsTop | kLHintsExpandX  , 1,1,1,1));
  stepList->MapWindow();
  
    

  hframe=new TGHorizontalFrame(scanFrame, 800,30);
  scanFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
  
 
  label = new TGLabel(hframe, "");
  label->Resize(50,30);
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  nModLabel=label;


  label = new TGLabel(hframe, "");
  label->Resize(50,30);
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  maxModLabel=label;


  label = new TGLabel(hframe, "");
  label->Resize(50,30);
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  chansPerModLabel=label;

  TGTextEntry*entry;

  hframe=new TGHorizontalFrame(scanFrame, 800,30);
  scanFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
 

  
  label = new TGLabel(hframe, "Bad Channels file: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);

  
  entry= new TGTextEntry(hframe);
  hframe->AddFrame(entry,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  entry->MapWindow();
  badChanFileEntry=entry;



  badChanFileEntry->Connect("ReturnPressed()","angCalWizard",this,"readBadChans()");



  label = new TGLabel(hframe, "Flat Field file: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);

  
  entry= new TGTextEntry(hframe);
  hframe->AddFrame(entry,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  entry->MapWindow();
  ffFileEntry=entry;



  ffFileEntry->Connect("ReturnPressed()","angCalWizard",this,"readFlatField()");

  hframe=new TGHorizontalFrame(scanFrame, 800,30);
  scanFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
 
  label = new TGLabel(hframe, "Angular conversion file: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);


  entry= new TGTextEntry(hframe);
  hframe->AddFrame(entry,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  entry->MapWindow();
  angConvFileEntry=entry;

  angConvFileEntry->Connect("ReturnPressed()","angCalWizard",this,"readAngularConversion()");

  
  hframe=new TGHorizontalFrame(scanFrame, 800,30);
  scanFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
 

  label = new TGLabel(hframe, "Total Offset: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);

  totalOffEntry=new TGNumberEntry(hframe);
  hframe->AddFrame(totalOffEntry,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  totalOffEntry->MapWindow();
  
  
  angDirCB=new TGCheckButton(hframe,"Invert direction");
  hframe->AddFrame(angDirCB,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  angDirCB->MapWindow();
  angDirCB->Connect("Clicked()","angCalWizard",this,"setAngDir()");
  
//   editEnergyList(-1);




  scanFrame = new TGGroupFrame(scan1Frame,"Step fitting",kVerticalFrame);
  scanFrame->SetTitlePos(TGGroupFrame::kLeft);
  scan1Frame->AddFrame(scanFrame,new TGLayoutHints( kLHintsTop | kLHintsExpandX , 5,5,5,5));
  scanFrame->MapWindow();
  
  


  plotModeBG=new TGButtonGroup( scanFrame ,"Plot mode",kHorizontalFrame);
  TGRadioButton *rb=new TGRadioButton(plotModeBG,"&None ");
  rb->SetDown(kTRUE);
  rb->MapWindow();
  rb=new TGRadioButton(plotModeBG,"&Raw data ");
  rb->MapWindow();
  rb=new TGRadioButton(plotModeBG,"&Processed data ");
  rb->MapWindow();
  rb=new TGRadioButton(plotModeBG,"&Angular Converted Data ");
  rb->MapWindow();
  rb=new TGRadioButton(plotModeBG,"&Flat Field ");
  rb->MapWindow();
  rb=new TGRadioButton(plotModeBG,"&Scan ");
  rb->MapWindow();
  plotModeBG->Connect("Clicked(Int_t)","angCalWizard",this,"setPlotMode(Int_t)");
  

  scanFrame ->AddFrame(plotModeBG,new TGLayoutHints(kLHintsTop | kLHintsRight | kLHintsExpandX, 5,5,5,5));
  plotModeBG->MapWindow();
  plotModeBG->SetLayoutHints(new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX),0);


  hframe=new TGHorizontalFrame(scanFrame, 800,30);
  scanFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
 


  label = new TGLabel(hframe, "Minimum angle: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
  
  angMinEntry=new TGNumberEntry(hframe);
  hframe->AddFrame(angMinEntry,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  angMinEntry->MapWindow();
   angMinEntry->SetNumber(18.5);
  
  

  label = new TGLabel(hframe, "Maximum angle: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
  


  
  angMaxEntry=new TGNumberEntry(hframe);
  hframe->AddFrame(angMaxEntry,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  angMaxEntry->MapWindow();
  angMaxEntry->SetNumber(19.5);
  
  




  stepListBG=new TGButtonGroup( scanFrame ,"",kHorizontalFrame);
  button = new TGTextButton(stepListBG,"&Preview ");
  button->MapWindow();
  button = new TGTextButton(stepListBG,"&Remove ");
  button->MapWindow();
  button = new TGTextButton(stepListBG,"&Fit ");
  button->MapWindow();
  scanFrame ->AddFrame(stepListBG,new TGLayoutHints(kLHintsTop | kLHintsRight | kLHintsExpandX, 5,5,5,5));


  stepListBG->Connect("Clicked(Int_t)","angCalWizard",this,"editStepList(Int_t)");


  stepListBG->MapWindow();
  stepListBG->SetLayoutHints(new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX),0);


  



  
//    // Creates widgets of the example
  fScanCanvas = new TRootEmbeddedCanvas ("Ecanvas",hpage,1000,500);
  hpage->AddFrame(fScanCanvas, new TGLayoutHints(kLHintsBottom | kLHintsCenterX | kLHintsExpandX | kLHintsExpandY, 5,5,5,5));

  fScanCanvas->Resize();
  fScanCanvas->GetCanvas()->Update();
  fScanCanvas->MapWindow();
  hpage->MapSubwindows();
  

}

void angCalWizard::moduleCalibrationPage() {
 TGHorizontalFrame *hframe;
  TGLabel *label;
 
  moduleCalibrationFrame = new TGGroupFrame(page,"",kVerticalFrame);
  moduleCalibrationFrame->SetTitlePos(TGGroupFrame::kLeft);
  page->AddFrame(moduleCalibrationFrame,new TGLayoutHints( kLHintsTop | kLHintsExpandX , 5,5,5,5));
  moduleCalibrationFrame->MapWindow();
  



  hframe=new TGHorizontalFrame(moduleCalibrationFrame, 800,30);
  moduleCalibrationFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
 

  centerCB=new TGCheckButton(hframe,"Center: ");
   hframe->AddFrame(centerCB,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  centerCB->MapWindow();
 
  centerEntry=new TGNumberEntry(hframe);
   hframe->AddFrame(centerEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  centerEntry->MapWindow();
  
  centerLabel=new TGLabel(hframe,"");
   hframe->AddFrame(centerLabel,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  centerLabel->MapWindow();
  
  
  hframe=new TGHorizontalFrame(moduleCalibrationFrame, 800,30);
  moduleCalibrationFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
 

  conversionCB=new TGCheckButton(hframe,"Conversion: ");
   hframe->AddFrame(conversionCB,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  conversionCB->MapWindow();
 
  conversionEntry=new TGNumberEntry(hframe);
   hframe->AddFrame(conversionEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  conversionEntry->MapWindow();
  
  conversionLabel=new TGLabel(hframe,"");
   hframe->AddFrame(conversionLabel,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  conversionLabel->MapWindow();
  
  
  hframe=new TGHorizontalFrame(moduleCalibrationFrame, 800,30);
  moduleCalibrationFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();
 

  offsetCB=new TGCheckButton(hframe,"Offset: ");
   hframe->AddFrame(offsetCB,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  offsetCB->MapWindow();
 
  offsetEntry=new TGNumberEntry(hframe);
   hframe->AddFrame(offsetEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  offsetEntry->MapWindow();
  
  offsetLabel=new TGLabel(hframe,"");
   hframe->AddFrame(offsetLabel,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 1,1,1,1));
  offsetLabel->MapWindow();
  
  


  moduleFitBG=new TGButtonGroup(moduleCalibrationFrame,"",kHorizontalFrame);
  TGTextButton *b=new  TGTextButton(moduleFitBG,"&<< Previous Module");
  b->MapWindow();
  b=  new TGTextButton(moduleFitBG,"&this module");
  b->MapWindow();
  b=  new TGTextButton(moduleFitBG,"&Next Module >>");
  b->MapWindow();
  moduleCalibrationFrame->AddFrame(moduleFitBG,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 1,1,1,1));
  moduleFitBG->MapWindow();
  moduleFitBG->SetLayoutHints(new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX),0);

  moduleFitBG->Connect("Clicked(Int_t)","angCalWizard",this,"scrollModule(Int_t)");
  



  fModulecanvas = new TRootEmbeddedCanvas ("Ecanvas",hpage,800,800);
  hpage->AddFrame(fModulecanvas, new TGLayoutHints(kLHintsBottom | kLHintsCenterX | kLHintsExpandX | kLHintsExpandY, 5,5,5,5));

  fModulecanvas->Resize();

  fModulecanvas->GetCanvas()->Update();
  fModulecanvas->MapWindow();
  hpage->MapSubwindows();
  

}








void angCalWizard::angCalFileDialog() {
  const char *filetypes[] = { 
   "Energy Calibration Files",    "*.angcal",
   "All files",     "*",
   0,               0 
  };


  char dir[1000];

  int c=string::npos;
  c=string(angCalFileEntry->GetText()).rfind('/');
  
  if (c!=string::npos)
    strcpy(dir,(string(angCalFileEntry->GetText()).substr(0,c+1)).c_str());
  else
    strcpy(dir,"");



  TGFileInfo fi;
  fi.fFileTypes = filetypes;
  fi.fIniDir=StrDup(dir);
  new TGFileDialog(gClient->GetRoot(), this, kFDOpen, &fi);
 
 if (fi.fFilename) {
   cout << "Selected file " << fi.fFilename << endl;
   angCalFileEntry->SetText(fi.fFilename);


 

 } else
   cout << "No file selected" << endl;
 
 //return fi.fFilename;



}
void angCalWizard::saveAngConvFile() {

  string fname=string(outFileEntry->GetText());

  cout << "Writing to file "<< fname<< endl;

  
  angleConversionConstant *myAngOff=new angleConversionConstant[maxNumberOfModules];
  for (int i=0; i<numberOfModules; i++) {
    myAngOff[i].center=fitAngOff[i].center;
    myAngOff[i].ecenter=fitAngOff[i].ecenter;
    myAngOff[i].r_conversion=fitAngOff[i].r_conversion;
    myAngOff[i].er_conversion=fitAngOff[i].er_conversion;
    myAngOff[i].offset=fitAngOff[i].offset-fitAngOff[0].offset;
    myAngOff[i].eoffset=fitAngOff[i].eoffset;
  }
  for (int i=numberOfModules; i<maxNumberOfModules; i++) {
    myAngOff[i].center=angOff[i].center;
    myAngOff[i].ecenter=angOff[i].ecenter;
    myAngOff[i].r_conversion=angOff[i].r_conversion;
    myAngOff[i].er_conversion=angOff[i].er_conversion;
    myAngOff[i].offset=angOff[i].offset-fitAngOff[0].offset;
    myAngOff[i].eoffset=angOff[i].eoffset;
  }


  angularConversionStatic::writeAngularConversion(fname,numberOfModules,myAngOff);

  delete [] myAngOff;

}

void angCalWizard::outFileDialog() {
  const char *filetypes[] = { 
   "Angular Conversion files",    "*.off",
   "Angular Conversion files",    "*.angconv",
   "All files",     "*",
   0,               0 
  };


  char dir[1000];
  
  // strcpy(dir,myDir.c_str());
  int c=string::npos;
  c=string(outFileEntry->GetText()).rfind('/');
  
  if (c!=string::npos)
    strcpy(dir,(string(outFileEntry->GetText()).substr(0,c+1)).c_str());
  else
    strcpy(dir,"");

  TGFileInfo fi;
  fi.fFileTypes = filetypes;
  fi.fIniDir=StrDup(dir);

  new TGFileDialog(gClient->GetRoot(), this, kFDSave, &fi);
 
  if (fi.fFilename) {
    cout << "Selected file " << fi.fFilename << endl;
    c=string(fi.fFilename).rfind('.');
    if (c!=string::npos) {
    
      cout << "extension " << string(fi.fFilename).substr(c+1) << endl;
      if (string(fi.fFilename).substr(c+1,2)==string("sn")) {
	outFileEntry->SetText((string(fi.fFilename).substr(0,c)).c_str());
	return;
      }      else if   (string(fi.fFilename).substr(c+1,3)==string("cal")) {
	outFileEntry->SetText((string(fi.fFilename).substr(0,c)).c_str());
	return;
      }
    }
    
    outFileEntry->SetText(fi.fFilename);
  } else
    cout << "No file selected" << endl;
 



}

void angCalWizard::createRawDataHisto(string fname) {

  int nch=channelsPerModule*numberOfModules;
  if (previewH1)
    delete previewH1;

  previewH1=TSlsDetector::dataFileHistogram(nch,fname);
  
  
  
  
  previewH1->SetMarkerStyle(20);
  previewH1->SetMarkerColor(4);
  previewH1->SetStats(kFALSE);
  previewH1->GetXaxis()->SetTitle("Channel number");
  previewH1->GetYaxis()->SetTitle("Counts");
 

  
}

void angCalWizard::readAngularConversion(string fname) {
  if (angOff) {
    delete [] angOff; angOff=NULL;
  }
  if (fitAngOff) {
    delete [] fitAngOff;
    fitAngOff=NULL;
  }
  if (fitted) {
    delete [] fitted;
    fitted=NULL;
  }
  cout << "Del" << endl;
  angOff=new angleConversionConstant[maxNumberOfModules];
  fitAngOff=new angleConversionConstant[maxNumberOfModules];
  fitted=new int[maxNumberOfModules];

  angularConversionStatic::readAngularConversion(fname ,maxNumberOfModules , angOff); 


  cout << "angoff" << endl;
  for (int im=0; im<maxNumberOfModules; im++) {
    cout << "module " << im << endl;
    myAngCal->setAngularConversionConstants(im, angOff+im);
  }

}

void angCalWizard::readBadChans(string fname) {


  int maxch=channelsPerModule*maxNumberOfModules;

  if (badChannelsList) {
    delete [] badChannelsList;
    nBad=0;
  }

  badChannelsList=new int[maxch];
  
  
  badChannelCorrections::readBadChannelCorrectionFile(fname,nBad,badChannelsList);
  

}


void angCalWizard::readFlatField(string fname) {
  int nch=channelsPerModule*numberOfModules;
  if (ffH1) {
    delete ffH1;
    ffH1=NULL;
  }
  ffH1=TSlsDetector::dataFileHistogram(nch,fname);
  ffH1->SetMarkerColor(3);
  ffH1->SetMarkerStyle(20);
  ffH1->SetStats(kFALSE);
  ffH1->SetMinimum(0);
  ffH1->SetMaximum(10);
  
  TSlsDetector::normalizeFF(ffH1);
}


void angCalWizard::createProcessedDataHisto() {

 

  if (processedH1)
    delete processedH1;

  if (previewH1==NULL)
    return;

  processedH1=(TH1F*)previewH1->Clone("processed");
  processedH1->SetMarkerColor(2);
  processedH1->SetMarkerStyle(24);
  processedH1->SetLineColor(2);
  
  cout << ffH1 << " " << nBad << endl;
  TSlsDetector::processData(processedH1,ffH1,nBad,badChannelsList);
  

}



void  angCalWizard::createFinalDataGraph(double pos) {

  if (gStep)
    delete gStep;
  angleConversionConstant **ao=new angleConversionConstant*[maxNumberOfModules];
  int *dum=new int[maxNumberOfModules];
  int *mf=new int[maxNumberOfModules];
  for (int i=0; i<maxNumberOfModules; i++) {

    dum[i]=channelsPerModule;
    mf[i]=1;
    ao[i]=angOff+i;
  }
  int angdir;
  if (angDirCB->IsDown())
    angdir=-1;
  else
    angdir=1;

  gStep= TSlsDetector::convertAngles(processedH1,pos, dum, ao, mf, 0., totalOffEntry->GetNumber(), angdir, nBad, badChannelsList);


  if (gStep) {
    gStep->SetMarkerColor(2);
    gStep->SetMarkerStyle(20);
    gStep->GetXaxis()->SetTitle("Angle");
    gStep->GetYaxis()->SetTitle("Counts");
    gStep->Sort();
  } 

  delete [] dum;
  delete [] mf;
  delete [] ao;

}
void angCalWizard::previewSteps(){
  if (scanH2)
    delete scanH2;



  TList *myList=new TList();
  scanStep *s=NULL, *s1=NULL;;
  char fname[10000];

  int c=string::npos;

  for (int i=0; i<scanList->GetEntries(); i++) {
    s1=(scanStep*)scanList->At(i);
    if (s1) {
      //   cout << "add to list" << endl;
      c=string(s1->getFileName()).rfind('/');
      //s=new scanStep(s1);
      strcpy(fname,(myDir+(s1->getFileName()).substr(c+1,string::npos)+string(".raw")).c_str());
      s=new scanStep(s1->getValue(),fname);
      //s->setFileName();
      myList->Add(s);
    }
  }
  //  cout << "creating 2d histo" << endl;
  scanH2=TSlsDetector::dataScanHistogram(channelsPerModule*numberOfModules,myList);
  scanH2->SetTitle(angCalFileEntry->GetText());
  scanH2->GetXaxis()->SetTitle("Channel number");
  scanH2->GetYaxis()->SetTitle("Position");
  scanH2->SetStats(kFALSE);;
  
  
  for (int i=myList->GetEntries()-1; i>=0; i--) {
    //  cout << "remove from list" << endl;
      s=(scanStep*)myList->At(i);
      myList->Remove(s);
      delete s;
  }
  delete myList;
  // cout << "done" << endl;

}

void angCalWizard::previewStep() {
  
  int id=stepList->GetSelected();

  scanStep *s=(scanStep*)scanList->At(id);
  if (s) {
    createStep(s);
    createFinalDataGraph(s->getValue());
    
    setPlotMode(-1);
  }
  
}



void angCalWizard::createStep(scanStep *s) {
  


  if (s==NULL)
    return;

  int maxch=channelsPerModule*maxNumberOfModules;
  int nch=channelsPerModule*numberOfModules;


  char tit[1000];

  

  int c=string::npos;

  c=string(s->getFileName()).rfind('/');

  createRawDataHisto(myDir+(s->getFileName()).substr(c+1,string::npos)+string(".raw"));


  sprintf(tit,"Position %f",s->getValue());
  previewH1->SetTitle(tit);


  createProcessedDataHisto();

  
}

void angCalWizard::fitStep() {
  

  int id=stepList->GetSelected();

  scanStep *s=(scanStep*)scanList->At(id);
  fitStep(s);

  setPlotMode(3);

}



void angCalWizard::fitStep(scanStep *s, int save){

  if (s==NULL)
    return;
  
  createStep(s);

  if (processedH1==NULL)
    return;
  myAngCal->setFitRange(angMinEntry->GetNumber(), angMaxEntry->GetNumber());
  myAngCal->fitCalibrationStep(processedH1,s->getValue(),save);
  cout << "step fitted " << endl;
}













void angCalWizard::setPlotMode(Int_t i) {
  

  cout << "Selected plot mode " << i << endl;

  TCanvas *fCanvas = fScanCanvas->GetCanvas();
  if (i==-1) {
     for (int ib=1; ib<6; ib++) {
       if (((TGRadioButton*)(plotModeBG->Find(ib)))->IsDown())
	i=ib;
     }
     cout << "Selected plot mode " << i << endl;
  }



  fCanvas->cd();
  switch (i) {
  case 1:
    myAngCal->setPlotFlag(0);
    return;
  case 2:
    if (previewH1)
      previewH1->Draw("LP");
    myAngCal->setPlotFlag(1);
    break;
  case 3:
    myAngCal->setPlotFlag(1);
    if (processedH1)
      processedH1->Draw("LP");
    cout <<  "drawing " << processedH1 << endl;
    break;
  case 4:
    if (gStep) {
      gStep->Draw("ALP");
      gStep->GetXaxis()->SetRangeUser(angMinEntry->GetNumber(), angMaxEntry->GetNumber());
    }
    myAngCal->setPlotFlag(1);
    break;
  case 5:
    if (ffH1)
      ffH1->Draw("LP");
    myAngCal->setPlotFlag(0);
    break;
  case 6:
    if (scanH2)
      scanH2->Draw("COLZ");
    myAngCal->setPlotFlag(0);
    break;
  default:
    return;
    myAngCal->setPlotFlag(0);
  }

  fCanvas->SetLogz();
  fCanvas->Update();


}
