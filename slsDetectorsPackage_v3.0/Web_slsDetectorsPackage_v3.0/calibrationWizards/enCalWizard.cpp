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
#include <TGComboBox.h>
#include <TH2F.h>
#include <TColor.h>
#include <TH1F.h>
#include <TGraphErrors.h>
#include <THStack.h>
#include "enCalLogClass.h"
#include "fileIOStatic.h"
#include "energyCalibration.h"
#include "energyConversion.h"
#include "scanStep.h"


#include <stdio.h>
#include <iostream>
#include <fstream>

#include "enCalWizard.h"

using namespace std;



#define DEFAULTFN "run_0.encal"


enCalWizard::enCalWizard(const TGWindow *p,UInt_t w,UInt_t h)
  : TGMainFrame(p,w,h), iPage(0), numberOfModules(-1), channelsPerModule(-1), error(0), goodData(0), previewH2(0), energyH2(0), mode(0), iModule(0), iEnergy(0) {



  myEnCal=new energyCalibration();
  energyList=new TList();
  myDir=string("./");
  strcpy(detectorSettings,"none");
  strcpy(modulesSerialNumbers,"none");
  previewH1=new THStack();
  previewGraph=new TGraphErrors();
  previewGraph->SetMarkerStyle(20);
  

  vframe=new TGVerticalFrame(this, 800,1200);

  hpage=new TGHorizontalFrame(vframe, 800,1200);
  page=new TGVerticalFrame(hpage, 1500,1200);

  // TGHorizontalFrame *hframe=new TGHorizontalFrame(vframe, 800,100);
  advancementBG=new TGButtonGroup(vframe,"",kHorizontalFrame);

 
  for (int i=0; i<100; i++) {
    h1Modules[i]=NULL;
    fileSaved[i]=0;
  }




  TGTextButton *goToCalibrationButton = new TGTextButton( advancementBG,"&Proceed to Modules Calibration");  
  goToCalibrationButton->MapWindow();
  TGTextButton *finishedButton = new TGTextButton( advancementBG,"&Finished ");
  finishedButton->SetEnabled(kFALSE);
  finishedButton->MapWindow();
  TGTextButton *exitButton = new TGTextButton( advancementBG,"&Exit ");
  exitButton->MapWindow();
  // hframe->AddFrame(exit, new TGLayoutHints(kLHintsRight,5,5,3,4));

  hpage->AddFrame(page,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 10,10,10,1));

  vframe->AddFrame(hpage,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 10,10,10,1));
  
  vframe->AddFrame(advancementBG,new TGLayoutHints(kLHintsExpandX, 10,10,10,1));
  //new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
 
  AddFrame(vframe,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 10,10,10,1));
  advancementBG->Connect("Clicked(Int_t)","enCalWizard",this,"changePage(Int_t)");

  // changePage(-1);

  vframe->MapWindow();
  hpage->MapWindow();
  advancementBG->MapWindow();
   // Sets window name and shows the main frame
   SetWindowName("Energy Calibration");
   MapSubwindows();
   // Resize(GetDefaultSize());
   MapWindow();
   Resize(1500,1200);
}





void enCalWizard::selectEnergy(Int_t i){
  editEnergyList(-1); 
  energyH2=(TH2F*)energyList->At(energyListCombo->GetSelected()-1); 
  cout << "selected " << energyListCombo->GetSelected() << endl;
  if (energyH2)
    cout << "Histogram is " << energyH2->GetTitle() << endl;
  else
    cout << "No histogram in list!" << endl;


}



void enCalWizard::editEnergyList(Int_t i) {


  switch (i) {
  case -1:
    break;
  case 1:
    cout << "Preview selected energy"<< endl;
    goodData=0;
    if (energyList->FindObject(previewH2)==0)
      delete previewH2;
    previewH2=(TH2F*)energyList->At(energyListCombo->GetSelected()-1);
    previewEnergy();
    editNewEnergy(-1);
    break;
  case 2:
    cout << "Remove selected energy"<< endl;
    removeEnergy();
    break;
  default:
    cout << "Unknown button "<< i << endl;
  }


  if (energyH2) {
    energyListBG->GetButton(1)->SetEnabled(kTRUE);
    energyListBG->GetButton(2)->SetEnabled(kTRUE);
  } else {
    energyListBG->GetButton(1)->SetEnabled(kFALSE);
    energyListBG->GetButton(2)->SetEnabled(kFALSE);
  }
  
  
}

void enCalWizard::editNewEnergy(Int_t i) {


  switch (i) {
  case -1:
    break;
  case 1:
    cout << "Preview energy calibration log file"<< endl;
    previewEnCal();
    break;
  case 2:
    cout << "Add this energy"<< endl;
    addEnergy();
    goodData=0;
    break;
  default:
    cout << "Unknown button "<< i << endl;
  }

  if (error==0 && goodData==1) {
    newEnergyBG->GetButton(2)->SetEnabled(kTRUE);
  } else {
    newEnergyBG->GetButton(2)->SetEnabled(kFALSE);
  }

  
}




void enCalWizard::addEnergy() {

  cout << "Add energy function " << endl;

  
  int ie=energyList->GetEntries();


  energyList->Add(previewH2);


 

  if (ie>=100)
    cout << "too many energies!" << endl;
  else
    energies[ie]=enEntry->GetNumber();

  energyListCombo->AddEntry(previewH2->GetTitle(),energyListCombo->GetNumberOfEntries()+1);
  energyListCombo->Select(energyListCombo->GetNumberOfEntries());
  

  //fMain->MapSubwindows();
energyListCombo->Resize(energyListCombo->GetDefaultSize());
//fMain->MapWindow();

  changePage(-1);
}


void enCalWizard::removeEnergy() {

  int id=energyListCombo->GetSelected();

  if (energyH2) {
    energyListCombo->RemoveEntries(id,energyListCombo->GetNumberOfEntries());
    energyList->Remove(energyH2);
    if (previewH2==energyH2)
      previewH2=NULL;
    delete energyH2;
  }

  for (int i=id-1; i<energyList->GetEntries(); i++) {
    energyListCombo->AddEntry(((TH2F*)energyList->At(i))->GetTitle(),i+1);
    energies[i]=energies[i+1];
  }


  changePage(-1);

  cout << "Remove energy function " << endl;
}







void enCalWizard::changePage(Int_t i) {

  

  switch (i) {
  case -1:
    break;
  case 1:

    if (mode==0) {

      
      ((TGTextButton*)advancementBG->GetButton(1))->SetText( "&Back to Energy Setup");
      cout << "Start module calibration"<< endl;
      mode=1;
      // advancementBG->GetButton(1)->SetEnabled(kFALSE);

    }  else {


      
     
      ((TGTextButton*)advancementBG->GetButton(1))->SetText( "&Proceed to module calibration");
      cout << "Back to energy setup"<< endl;
      mode=0;

    }
    break;
  case 2:
    cout << "Finished"<< endl;
//     if (fileSaved[iModule]==0 && autSaveCheckButton->IsDown()==kFALSE)
//       writeCalibrationFile();

    gApplication->Terminate(0);
    break;
  case 3:
    cout << "Exit root!"<< endl;
    gApplication->Terminate(0);
    break;
    
  default:
    cout << "Unknown button "<< i << endl;
  }


  if (mode==0) {
  
      page->HideFrame(moduleCalibrationFrame);
      hpage->HideFrame(fModulecanvas);
      page->MapWindow();

      
      page->ShowFrame(newEnergyFrame);
      page->ShowFrame(energyListBG);
      hpage->ShowFrame(fEcanvas);
      

      page->MapWindow();
      hpage->MapWindow();

  } else {

    // moduleNumberEntry->SetLimitValues(0,numberOfModules-1);
    page->ShowFrame(moduleCalibrationFrame);
    hpage->ShowFrame(fModulecanvas);
    page->MapWindow();
    
    page->HideFrame(newEnergyFrame);
    page->HideFrame(energyListBG);
    hpage->HideFrame(fEcanvas);
    
    outFileEntry->SetText((string("newcal_")+string(detectorSettings)).c_str());
    
    for (int i=0; i<100; i++) {
      if (h1Modules[i]) {
	delete h1Modules[i];
	h1Modules[i]=NULL;
      }
    }

    scrollModule(-1);
    scrollEnergy(-1);
    //moduleNumberChanged();
    page->MapWindow();
    hpage->MapWindow();
  }


  
  if (energyList->GetSize()>=2)
    advancementBG->GetButton(1)->SetEnabled(kTRUE);
  else
    advancementBG->GetButton(1)->SetEnabled(kFALSE);
    
  
}


void  enCalWizard::scrollModule(Int_t ib) {

  
  char tmp[100];

  switch (ib) {
  case 1:
//     if (autoSaveCheckButton->IsDown()==kFALSE)
//       writeCalibrationFile();
    cout << "Moving to previous module " ;
    if (iModule>0)
      iModule--;
    cout << iModule << endl;
    break;
    
  case 3:
//     if (autoSaveCheckButton->IsDown()==kFALSE)
//       writeCalibrationFile();
    cout << "Moving to next module " ;
    if (iModule<(numberOfModules-1))
      iModule++;
    cout << iModule << endl;
    break;
   
  default:
    cout << "Module number is " << iModule << endl;
  
  }


  sprintf(tmp,"Module %d sn%03x",iModule,modSN[iModule]);
 
  ((TGTextButton*)moduleFitBG->GetButton(2))->SetText(tmp);

  if (iModule>0)
    moduleFitBG->GetButton(1)->SetEnabled(kTRUE);
  else
    moduleFitBG->GetButton(1)->SetEnabled(kFALSE);
    

  
  if (iModule<(numberOfModules-1))
    moduleFitBG->GetButton(3)->SetEnabled(kTRUE);
  else
    moduleFitBG->GetButton(3)->SetEnabled(kFALSE);
    
  moduleNumberChanged();

}


void  enCalWizard::scrollEnergy(Int_t ib) {

  

  switch (ib) {
  case 1:
    cout << "Moving to previous energy " ;
    if (iEnergy>0)
      iEnergy--;
    cout << iEnergy << endl;
    break;
    
  case 3:
    cout << "Moving to next energy " ;
    if (iEnergy<(energyList->GetEntries()-1))
      iEnergy++;
    cout << iEnergy << endl;
    break;

  case 2:
    fitEnergy(iModule,iEnergy);

  default:
    cout << "Energy number is " << iEnergy << " value " << ((TH2F*)energyList->At(iEnergy))->GetTitle() << endl;
  
  }

 
  ((TGTextButton*)energyFitBG->GetButton(2))->SetText(((TH2F*)energyList->At(iEnergy))->GetTitle());

  ((TGTextButton*)energyFitBG->GetButton(2))->SetForegroundColor(TColor::Number2Pixel(iEnergy+2));


  //update labels


  


 THStack *hs=h1Modules[iModule];


  TF1 *f1;

  if (hs==NULL) return;

  TList *hl=hs->GetHists();

  if (hl==NULL) return;

  TH1F *h1=(TH1F*)hl->At(iEnergy);
  
  if (h1==NULL) return;

  
  TF1 *f=h1->GetFunction("fscurve");

  if (f==NULL) return;
  
  char tmp[100];

 
  sprintf(tmp,"%0.2f+-%0.2f",f->GetParameter(0),f->GetParError(0));
  pedestalLabel->SetText(tmp);

  sprintf(tmp,"%0.2f+-%0.2f",f->GetParameter(1),f->GetParError(1));
  pedSlopeLabel->SetText(tmp);


  sprintf(tmp,"%0.2f+-%0.2f",f->GetParameter(2),f->GetParError(2));
  flexLabel->SetText(tmp);


  sprintf(tmp,"%0.2f+-%0.2f",f->GetParameter(3),f->GetParError(3));
  noiseLabel->SetText(tmp);
  

  sprintf(tmp,"%0.2f+-%0.2f",f->GetParameter(4),f->GetParError(4));
  countsLabel->SetText(tmp);


  sprintf(tmp,"%0.2f+-%0.2f",f->GetParameter(5),f->GetParError(5));
  csSlopeLabel->SetText(tmp);
  



  if (iEnergy>0)
    energyFitBG->GetButton(1)->SetEnabled(kTRUE);
  else
    energyFitBG->GetButton(1)->SetEnabled(kFALSE);
    

  
  if (iEnergy<(energyList->GetEntries()-1))
    energyFitBG->GetButton(3)->SetEnabled(kTRUE);
  else
    energyFitBG->GetButton(3)->SetEnabled(kFALSE);
    
  
}


void enCalWizard::moduleNumberChanged() {

  char tmp[100];

  int imod=iModule;



  if (h1Modules[imod]==NULL)
    createModuleHistos(imod);
  
  if (h1Modules[imod])
    previewH1=h1Modules[imod];
  
  fitModule(imod);

  TCanvas *fCanvas = fModulecanvas->GetCanvas();
  
  fCanvas->cd(1);
  previewH1->Draw("P NOSTACK");

  fCanvas->Update();
  
  previewH1->GetXaxis()->SetTitle("Threshold");
  previewH1->GetYaxis()->SetTitle("Counts");
  

  fCanvas->cd(2);
  previewGraph->Draw("AP");
  previewGraph->GetXaxis()->SetTitle("Energy (keV)");
  previewGraph->GetYaxis()->SetTitle("Threshold");
  
  fCanvas->Update();
  //  cout << " drawing" << endl;


}

void enCalWizard::createModuleHistos(int imod) {

  //  cout << "Module number is " << moduleNumberEntry->GetIntNumber() << endl;

  // int imod=moduleNumberEntry->GetIntNumber();

  TList *hl;
  int nh;
  TH1F *h1;
  char tmp[100];

  if (h1Modules[imod]) {
    
    hl=h1Modules[imod]->GetHists();
    
    if (hl)
      hl->GetEntries();
    else
      nh=0;
  
    for (int ih=nh-1; ih>=0; ih--) {
      h1=(TH1F*)hl->At(ih);
      h1Modules[imod]->RecursiveRemove(h1);
      delete h1;
    }
  
  } else
    h1Modules[imod]=new THStack();
  

  for (int ien=0; ien<energyList->GetEntries(); ien++) {
    h1=myEnCal->createMedianHistogram(((TH2F*)energyList->At(ien)),imod*channelsPerModule,channelsPerModule); 
    h1->SetTitle(((TH2F*)energyList->At(ien))->GetTitle());
    h1Modules[imod]->Add(h1);
    h1->SetLineColor(ien+2);
    h1->SetMarkerColor(ien+2);
    h1->SetMarkerStyle(21+ien);
    fitEnergy(imod,ien);
    h1->SetStats(kFALSE);
  }
  
  sprintf(tmp,"Module number %d sn0x%03x",imod,modSN[imod]);
  h1Modules[imod]->SetTitle(tmp);
  


}
void enCalWizard::fitModule(int imod) {
 

  THStack *hs=h1Modules[imod];


  if (hs==NULL) return;

  TList *hl=hs->GetHists();

  if (hl==NULL) return;

  TH1F *h1;
  
  Double_t flex[100], eflex[100], een[100];



  for (int ien=0; ien<hl->GetEntries(); ien++) {

    een[ien]=0;

    h1=(TH1F*)hl->At(ien);
    if (h1==NULL) return;
    
    if (h1->GetFunction("fscurve"))
      h1->GetFunction("fscurve")->SetLineColor(ien+2);
    else
      return;
    
    flex[ien]=h1->GetFunction("fscurve")->GetParameter(2);
    eflex[ien]=h1->GetFunction("fscurve")->GetParError(2);
    

  }
  
  if (previewGraph)
    delete previewGraph;

  Double_t gain, off, egain, eoff;
  
  previewGraph=myEnCal->linearCalibration(hl->GetEntries(), energies, een, flex, eflex, gain, off, egain, eoff);  
  previewGraph->SetMarkerStyle(20);
  previewGraph->SetTitle("");
  
  char tmp[100];

  sprintf(tmp,"%0.4f+-%0.4f",gain,egain);
  gainLabel->SetText(tmp);
  

  sprintf(tmp,"%0.4f+-%0.4f",off,eoff);
  offsetLabel->SetText(tmp);
  
  if (autoSaveCheckButton->IsDown()==kFALSE)
    writeCalibrationFile();
}





void enCalWizard::fitEnergy(int imod, int ien) {
 
  THStack *hs=h1Modules[imod];


  TF1 *f1;

  if (hs==NULL) return;

  TList *hl=hs->GetHists();

  if (hl==NULL) return;

  TH1F *h1=(TH1F*)hl->At(ien);
  
  if (h1==NULL) return;

  cout << "Fitting histogram " << h1->GetTitle() << endl;
  
  Double_t params[10], eparams[10];
  myEnCal->setFitRange(fitMinEntry->GetNumber(),fitMaxEntry->GetNumber()); 
  



  if (axisSignCheckButton->IsDown()) {
    myEnCal->setScanSign(-1); 
  } else
    myEnCal->setScanSign(1); 
  

  
  if (pedestalCheckButton->IsDown()) {
    myEnCal->fixParameter(0,pedestalEntry->GetNumber()); 
  } else
    myEnCal->releaseParameter(0);
  

  if (pedSlopeCheckButton->IsDown()) {
    myEnCal->fixParameter(1,pedSlopeEntry->GetNumber()); 
  } else
    myEnCal->releaseParameter(1);
  

  if (flexCheckButton->IsDown()) {
    myEnCal->fixParameter(2,flexEntry->GetNumber()); 
  } else
    myEnCal->releaseParameter(2);
  

  if (noiseCheckButton->IsDown()) {
    myEnCal->fixParameter(3,noiseEntry->GetNumber()); 
  } else
    myEnCal->releaseParameter(3);
  

  if (countsCheckButton->IsDown()) {
    myEnCal->fixParameter(4,countsEntry->GetNumber()); 
  } else
    myEnCal->releaseParameter(4);
  

  if (csSlopeCheckButton->IsDown()) {
    myEnCal->fixParameter(5,csSlopeEntry->GetNumber()); 
  } else
    myEnCal->releaseParameter(5);
  

  








  params[0]=pedestalEntry->GetNumber();
  params[1]=pedSlopeEntry->GetNumber();
  params[2]=flexEntry->GetNumber();
  params[3]=noiseEntry->GetNumber();
  params[4]=countsEntry->GetNumber();
  params[5]=csSlopeEntry->GetNumber();
 
  myEnCal->setStartParameters(params);
  f1=myEnCal->fitSCurve(h1,params, eparams);

  if (f1)
    f1->SetLineColor(ien+2);
  else
    return;

  char tmp[100];



  sprintf(tmp,"%0.2f+-%0.2f",params[0],eparams[0]);
  pedestalLabel->SetText(tmp);

  
  sprintf(tmp,"%0.2f+-%0.2f",params[1],eparams[1]);
  pedSlopeLabel->SetText(tmp);

  sprintf(tmp,"%0.2f+-%0.2f",params[2],eparams[2]);
  flexLabel->SetText(tmp);

  sprintf(tmp,"%0.2f+-%0.2f",params[3],eparams[3]);
  noiseLabel->SetText(tmp);

  
  sprintf(tmp,"%0.2f+-%0.2f",params[4],eparams[4]);
  countsLabel->SetText(tmp);

  
  sprintf(tmp,"%0.2f+-%0.2f",params[5],eparams[5]);
  csSlopeLabel->SetText(tmp);
  
  moduleNumberChanged();

  if (countsEntry->GetNumber()==-1)
    h1Modules[imod]->SetMaximum(params[4]*3);
  else
    h1Modules[imod]->SetMaximum(countsEntry->GetNumber()*3);

}






















void enCalWizard::moduleCalibrationPage() {
  
  TGNumberEntry *entry;

  moduleCalibrationFrame = new TGGroupFrame(page,"Module Energy Calibration",kVerticalFrame);
  moduleCalibrationFrame->SetTitlePos(TGGroupFrame::kLeft);
  page->AddFrame(moduleCalibrationFrame,new TGLayoutHints( kLHintsTop | kLHintsExpandX , 10,10,10,10));
  moduleCalibrationFrame->MapWindow();
   
  TGLabel *label;


//   moduleNumberEntry=new TGNumberEntry(hframe, 0.0, 12, 0, TGNumberFormat::kNESInteger, TGNumberFormat::kNEANonNegative,TGNumberFormat::kNELLimitMinMax, 0.,numberOfModules-1);                         //limit values);
//   hframe->AddFrame(enEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft|  kLHintsExpandX, 5, 5, 5, 5));
//   moduleNumberEntry->MapWindow();
//   moduleNumberEntry->Resize(150,30);

//   moduleNumberEntry->Connect("ValueChanged(Long_t)","enCalWizard",this,"moduleNumberChanged()");
//   moduleNumberEntry->Connect("ValueSet(Long_t)","enCalWizard",this,"moduleNumberChanged()");
//   moduleNumberEntry->Connect("ReturnPressed()", "enCalWizard", this, "moduleNumberChanged()");


  moduleFitBG=new TGButtonGroup(moduleCalibrationFrame,"",kHorizontalFrame);
  TGTextButton *b=new  TGTextButton(moduleFitBG,"&<< Previous Module");
  b->MapWindow();
  b=  new TGTextButton(moduleFitBG,"&this module");
  b->MapWindow();
  b=  new TGTextButton(moduleFitBG,"&Next Module >>");
  b->MapWindow();
  moduleCalibrationFrame->AddFrame(moduleFitBG,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  moduleFitBG->MapWindow();
  moduleFitBG->SetLayoutHints(new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX),0);

  moduleFitBG->Connect("Clicked(Int_t)","enCalWizard",this,"scrollModule(Int_t)");
  
  TGHorizontalFrame *hframe=new TGHorizontalFrame(moduleCalibrationFrame, 800,50);
  moduleCalibrationFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();

  label  = new TGLabel(hframe, "Output calibration File ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);

  
  outFileEntry=new TGTextEntry(hframe, (string("newcal_")+string(detectorSettings)).c_str(),1);
  hframe->AddFrame(outFileEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX, 0, 0, 0, 0));
  outFileEntry->MapWindow();
  outFileEntry->Resize(200,30);


  TGTextButton *browse = new TGTextButton( hframe,"&Browse ");
  browse->MapWindow();
  hframe->AddFrame(browse,new TGLayoutHints(kLHintsTop | kLHintsLeft , 0, 5, 0, 5));
  browse->MapWindow();
  browse->Resize(100,30);

  browse->Connect("Clicked()","enCalWizard",this,"outFileDialog()");





  b=  new TGTextButton(hframe,"&Write to file");
  b->MapWindow();
  hframe->AddFrame(b,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX, 0, 0, 0, 0));
  b->MapWindow();

  b->Connect("Clicked()","enCalWizard",this,"writeCalibrationFile()");
  saveButton=b;
  saveButton->SetEnabled(kFALSE);

  TGCheckButton *cb= new TGCheckButton(hframe, "Manual save");
  hframe->AddFrame(cb,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  cb->MapWindow();
  autoSaveCheckButton=cb;
  autoSaveCheckButton->SetDown(kTRUE);

  autoSaveCheckButton->Connect("Toggled(Bool_t)","TGTextButton",saveButton,"SetEnabled(Bool_t)");
  

  //moduleNumberEntry->Connect("ValueSet(Long_t)","enCalWizard",this,"moduleNumberChanged(Long_t)");
  //moduleNumberEntry->Connect("ChangedBy(const char*)","enCalWizard",this,"moduleNumberChanged(const char*)");


  energyFitBG=new TGButtonGroup(moduleCalibrationFrame,"",kHorizontalFrame);
 b=new  TGTextButton(energyFitBG,"&<< Previous Energy");
 b->MapWindow();
  b=  new TGTextButton(energyFitBG,"&this energy");
 b->MapWindow();
  b=  new TGTextButton(energyFitBG,"&Next Energy >>");
 b->MapWindow();
  moduleCalibrationFrame->AddFrame(energyFitBG,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  energyFitBG->MapWindow();
  energyFitBG->SetLayoutHints(new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX),0);

  energyFitBG->Connect("Clicked(Int_t)","enCalWizard",this,"scrollEnergy(Int_t)");



  hframe=new TGHorizontalFrame(moduleCalibrationFrame, 800,50);
  moduleCalibrationFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();

  label = new TGLabel(hframe, "Fit Range Minimum: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
  

  fitMinEntry=new TGNumberEntry(hframe, 0, 12, 0, TGNumberFormat::kNESRealTwo);                      
  hframe->AddFrame(fitMinEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft|  kLHintsExpandX, 5, 5, 5, 5));
  fitMinEntry->MapWindow();
  fitMinEntry->Resize(150,30);

  label = new TGLabel(hframe, "Fit Range Maximum: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
 
  fitMaxEntry=new TGNumberEntry(hframe, 1000, 12, 0, TGNumberFormat::kNESRealTwo);                        
  hframe->AddFrame(fitMaxEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft|  kLHintsExpandX, 5, 5, 5, 5));
  fitMaxEntry->MapWindow();
  fitMaxEntry->Resize(150,30);
  

  cb= new TGCheckButton(hframe, "Invert axis");
  hframe->AddFrame(cb,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  cb->MapWindow();
  axisSignCheckButton=cb;
  axisSignCheckButton->SetDown(kTRUE);

  hframe=new TGHorizontalFrame(moduleCalibrationFrame, 800,50);
  moduleCalibrationFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();

  cb= new TGCheckButton(hframe, "Pedestal: ");
  hframe->AddFrame(cb,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  cb->MapWindow();
  pedestalCheckButton=cb;

  entry=new TGNumberEntry(hframe, 0, 12, 0, TGNumberFormat::kNESRealTwo);                      
  hframe->AddFrame(entry,new TGLayoutHints(kLHintsTop | kLHintsLeft|  kLHintsExpandX, 5, 5, 5, 5));
  entry->MapWindow();
  entry->Resize(150,30);

  pedestalEntry=entry;



  label = new TGLabel(hframe, "");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
 

  pedestalLabel=label;








  cb= new TGCheckButton(hframe, "Pedestal slope: ");
  hframe->AddFrame(cb,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  cb->MapWindow();
  pedSlopeCheckButton=cb;
  pedSlopeCheckButton->SetDown(kTRUE);


  entry=new TGNumberEntry(hframe, 0, 12, 0, TGNumberFormat::kNESRealTwo);                      
  hframe->AddFrame(entry,new TGLayoutHints(kLHintsTop | kLHintsLeft|  kLHintsExpandX, 5, 5, 5, 5));
  entry->MapWindow();
  entry->Resize(150,30);


  pedSlopeEntry=entry;

  label = new TGLabel(hframe, "");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
 

  pedSlopeLabel=label;


  hframe=new TGHorizontalFrame(moduleCalibrationFrame, 800,50);
  moduleCalibrationFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();


  cb= new TGCheckButton(hframe, "Inflection Point: ");
  hframe->AddFrame(cb,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  cb->MapWindow();
  flexCheckButton=cb;



  entry=new TGNumberEntry(hframe, 600, 12, 0, TGNumberFormat::kNESRealTwo);                      
  hframe->AddFrame(entry,new TGLayoutHints(kLHintsTop | kLHintsLeft|  kLHintsExpandX, 5, 5, 5, 5));
  entry->MapWindow();
  entry->Resize(150,30);

  flexEntry=entry;

  label = new TGLabel(hframe, "");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
 

  flexLabel=label;

  cb= new TGCheckButton(hframe, "Noise: ");
  hframe->AddFrame(cb,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  cb->MapWindow();
  noiseCheckButton=cb;

  
  entry=new TGNumberEntry(hframe, 10, 12, 0, TGNumberFormat::kNESRealTwo, TGNumberFormat::kNEAPositive);                      
  hframe->AddFrame(entry,new TGLayoutHints(kLHintsTop | kLHintsLeft|  kLHintsExpandX, 5, 5, 5, 5));
  entry->MapWindow();
  entry->Resize(150,30);

  noiseEntry=entry;

  label = new TGLabel(hframe, "");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
 

  noiseLabel=label;

  hframe=new TGHorizontalFrame(moduleCalibrationFrame, 800,50);
  moduleCalibrationFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();

  cb= new TGCheckButton(hframe, "Counts: ");
  hframe->AddFrame(cb,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  cb->MapWindow();
  countsCheckButton=cb;

 
  
  entry=new TGNumberEntry(hframe, 1000, 12, 0, TGNumberFormat::kNESRealTwo);                      
  hframe->AddFrame(entry,new TGLayoutHints(kLHintsTop | kLHintsLeft|  kLHintsExpandX, 5, 5, 5, 5));
  entry->MapWindow();
  entry->Resize(150,30);

  countsEntry=entry;

  label = new TGLabel(hframe, "");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
 

  countsLabel=label;

  cb= new TGCheckButton(hframe, "Charge Sharing: ");
  hframe->AddFrame(cb,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  cb->MapWindow();
  csSlopeCheckButton=cb;


  entry=new TGNumberEntry(hframe, 0., 12, 0, TGNumberFormat::kNESRealTwo);                      
  hframe->AddFrame(entry,new TGLayoutHints(kLHintsTop | kLHintsLeft|  kLHintsExpandX, 5, 5, 5, 5));
  entry->MapWindow();
  entry->Resize(150,30);

  csSlopeEntry=entry;
 
  label = new TGLabel(hframe, "");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
 

  csSlopeLabel=label;

  hframe=new TGHorizontalFrame(moduleCalibrationFrame, 800,50);
  moduleCalibrationFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 1,1,1,1));
  hframe->MapWindow();


  label = new TGLabel(hframe, "Gain: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);

  gainLabel = new TGLabel(hframe, "-1 ");
  hframe->AddFrame(gainLabel,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  gainLabel->MapWindow();
  gainLabel->SetTextJustify(kTextLeft);


  label = new TGLabel(hframe, "Offset: ");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);


  offsetLabel = new TGLabel(hframe, "-1 ");
  hframe->AddFrame(offsetLabel,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  offsetLabel->MapWindow();
  offsetLabel->SetTextJustify(kTextLeft);

  

   // Creates widgets of the example
  fModulecanvas = new TRootEmbeddedCanvas ("Ecanvas",hpage,800,800);
  hpage->AddFrame(fModulecanvas, new TGLayoutHints(kLHintsBottom | kLHintsCenterX | kLHintsExpandX | kLHintsExpandY, 10,10,10,10));
  fModulecanvas->Resize();
  fModulecanvas->GetCanvas()->Divide(2,1);
  fModulecanvas->GetCanvas()->Update();
  fModulecanvas->MapWindow();
  hpage->MapSubwindows();

}

void enCalWizard::writeCalibrationFile() {

  char tmp[100];

  sprintf(tmp,".sn%03x",modSN[iModule]);

  string fname=string(outFileEntry->GetText())+string(tmp);

  cout << "writing to file " << fname << endl;
  
  Double_t gain, off;

  if (previewGraph) {
    if (previewGraph->GetFunction("pol1")) {
      off=previewGraph->GetFunction("pol1")->GetParameter(0);
      gain=previewGraph->GetFunction("pol1")->GetParameter(1);
    } else {
      cout << "Could not find fitfun" << endl;
      return;
    }
  } else {
      cout << "Could not find linear graph" << endl;
      return;
  }
  

  energyConversion::writeCalibrationFile(fname, gain, off);
  fileSaved[iModule]=1;

  int en=1;

  for (int i=0; i<numberOfModules; i++) {
    if (fileSaved[i]==0)
      en=0;
  }
  
  if (en)
    advancementBG->GetButton(2)->SetEnabled(kTRUE);
  else
    advancementBG->GetButton(2)->SetEnabled(kFALSE);
    

  
}





void enCalWizard::addEnergyPage() {


  TGGroupFrame *groupFrame = new TGGroupFrame(page,"Energy Calibration Summary",kVerticalFrame);
  groupFrame->SetTitlePos(TGGroupFrame::kLeft);
  page->AddFrame(groupFrame,new TGLayoutHints( kLHintsTop | kLHintsExpandX , 10,10,10,10));
  groupFrame->MapWindow();
  
 


  TGHorizontalFrame *hframe=new TGHorizontalFrame(groupFrame, 800,50);
  groupFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 10,10,10,10));
  hframe->MapWindow();
  
  TGLabel *label = new TGLabel(hframe, "Calibration energies:");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);

  energyListCombo=new TGComboBox(hframe,100);
  hframe->AddFrame(energyListCombo,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX | kLHintsExpandY, 3, 3, 3, 3));
  energyListCombo->Resize(150,20);
  energyListCombo->MapWindow();

  energyListCombo->Connect("Selected(Int_t)","enCalWizard",this,"selectEnergy(Int_t)");



  hframe=new TGHorizontalFrame(groupFrame, 800,100);
  groupFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX ,  10,10,10,10));
  hframe->MapWindow();
  





  hframe=new TGHorizontalFrame(groupFrame, 800,30);
  groupFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX ,  5,5,5,5));
  hframe->MapWindow();
  
  settingsLabel = new TGLabel(hframe, "");
  hframe->AddFrame(settingsLabel,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 5, 5, 5, 5));
  settingsLabel->MapWindow();
  settingsLabel->SetTextJustify(kTextLeft);

  nmodLabel = new TGLabel(hframe, "");
  hframe->AddFrame(nmodLabel,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 5, 5, 5, 5));
  nmodLabel->MapWindow();
  nmodLabel->SetTextJustify(kTextLeft);

  chansPerModLabel = new TGLabel(hframe, "");
  hframe->AddFrame(chansPerModLabel,new TGLayoutHints(kLHintsTop | kLHintsRight | kLHintsExpandX , 5, 5, 5, 5));
  chansPerModLabel->MapWindow();
  chansPerModLabel->SetTextJustify(kTextLeft);

  hframe=new TGHorizontalFrame(groupFrame, 800,30);
  groupFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX ,  5,5,5,5));
  hframe->MapWindow();
 
  
  modNumbersLabel = new TGLabel(hframe, "");
  hframe->AddFrame(modNumbersLabel,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 5, 5, 5, 5));
  modNumbersLabel->MapWindow();
  modNumbersLabel->SetTextJustify(kTextLeft);
























  energyListBG=new TGButtonGroup(page,"Selected energy actions",kHorizontalFrame);
  TGTextButton *button = new TGTextButton(energyListBG,"&Preview ");
  button->MapWindow();
  button = new TGTextButton(energyListBG,"&Remove ");
  button->MapWindow();
  page->AddFrame(energyListBG,new TGLayoutHints(kLHintsTop | kLHintsRight | kLHintsExpandX, 10,10,10,10));
  energyListBG->Connect("Clicked(Int_t)","enCalWizard",this,"editEnergyList(Int_t)");
  energyListBG->MapWindow();
  energyListBG->SetLayoutHints(new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX),0);


  editEnergyList(-1);



  newEnergyFrame = new TGGroupFrame(page,"New Energy",kVerticalFrame);
  newEnergyFrame->SetTitlePos(TGGroupFrame::kLeft);
  page->AddFrame(newEnergyFrame,new TGLayoutHints( kLHintsTop | kLHintsExpandX , 10,10,10,10));
  newEnergyFrame->MapWindow();
  
  



  hframe=new TGHorizontalFrame(newEnergyFrame, 800,30);
  newEnergyFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX , 5,5,5,5));
  hframe->MapWindow();
  
  label = new TGLabel(hframe, "X-ray energy (keV):");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft| kLHintsExpandX, 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
  label->Resize(150,30);

  enEntry=new TGNumberEntry(hframe, 0.0, 12, 0, TGNumberFormat::kNESRealTwo);
  hframe->AddFrame(enEntry,new TGLayoutHints(kLHintsTop |  kLHintsExpandX, 5, 5, 5, 5));
  enEntry->MapWindow();
  enEntry->Resize(150,30);

//    hframe=new TGHorizontalFrame(newEnergyFrame, 800,100);
//    newEnergyFrame->AddFrame(hframe,new TGLayoutHints(kLHintsTop | kLHintsExpandX ,  10,10,10,10));
//    hframe->MapWindow();
  
  label = new TGLabel(hframe, "Energy Calibration File Log:");
  hframe->AddFrame(label,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX , 5, 5, 5, 5));
  label->MapWindow();
  label->SetTextJustify(kTextLeft);
  label->Resize(200,30);


//   TGHorizontalFrame *hframe1=new TGHorizontalFrame(hframe, 700,100);
//   hframe->AddFrame(hframe1,new TGLayoutHints(kLHintsTop | kLHintsRight | kLHintsExpandX, 0, 0, 0, 0));
//   hframe1->MapWindow();

  
  enCalFileEntry=new TGTextEntry(hframe, DEFAULTFN,1);
  hframe->AddFrame(enCalFileEntry,new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX, 0, 5, 0, 5));
  enCalFileEntry->MapWindow();
  enCalFileEntry->Resize(200,30);

  TGTextButton *browse = new TGTextButton( hframe,"&Browse ");
  hframe->AddFrame(browse,new TGLayoutHints(kLHintsTop | kLHintsLeft , 0, 5, 0, 5));
  browse->MapWindow();
  browse->Resize(100,30);

  browse->Connect("Clicked()","enCalWizard",this,"enCalFileDialog()");





  newEnergyBG=new TGButtonGroup(newEnergyFrame,"",kHorizontalFrame);
  button = new TGTextButton(newEnergyBG,"&Preview ");
  button->MapWindow();
  button = new TGTextButton(newEnergyBG,"&Add to List ");
  button->MapWindow();
  newEnergyFrame->AddFrame(newEnergyBG,new TGLayoutHints(kLHintsTop | kLHintsRight | kLHintsExpandX, 5,5,5,5));
  //new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
 
  newEnergyBG->Connect("Clicked(Int_t)","enCalWizard",this,"editNewEnergy(Int_t)");
  newEnergyBG->MapWindow();
  newEnergyBG->SetLayoutHints(new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX),0);

  editNewEnergy(-1);



  
   // Creates widgets of the example
  fEcanvas = new TRootEmbeddedCanvas ("Ecanvas",hpage,800,800);
  fEcanvas->Resize();
  fEcanvas->GetCanvas()->Update();
  
  hpage->AddFrame(fEcanvas, new TGLayoutHints(kLHintsBottom | kLHintsCenterX | kLHintsExpandX | kLHintsExpandY, 10,10,10,10));


  fEcanvas->MapWindow();
  hpage->MapSubwindows();
  
}





void enCalWizard::enCalFileDialog() {
  const char *filetypes[] = { 
   "Energy Calibration Files",    "*.encal",
   "All files",     "*",
   0,               0 
  };


  char dir[1000];

  int c=(int)string::npos;
  c=string(enCalFileEntry->GetText()).rfind('/');
  
  if (c!=string::npos)
    strcpy(dir,(string(enCalFileEntry->GetText()).substr(0,c+1)).c_str());
  else
    strcpy(dir,"");



  TGFileInfo fi;
  fi.fFileTypes = filetypes;
  fi.fIniDir=StrDup(dir);
 new TGFileDialog(gClient->GetRoot(), this, kFDOpen, &fi);
 
 if (fi.fFilename) {
   cout << "Selected file " << fi.fFilename << endl;
   enCalFileEntry->SetText(fi.fFilename);


 

 } else
   cout << "No file selected" << endl;
 
 // return fi.fFilename;



}


void enCalWizard::outFileDialog() {
  const char *filetypes[] = { 
   "Energy Calibration Files",    "*.sn*",
   "Energy Calibration Files",    "*.cal",
   "All files",     "*",
   0,               0 
  };


  char dir[1000];
  
  // strcpy(dir,myDir.c_str());
  int c=(int)string::npos;
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


void enCalWizard::previewEnCal() {
  

  goodData=0;
  error=0;

  ifstream infile(enCalFileEntry->GetText());
  char name[100];
  char text[1000], sn[10];
  double thr;
  char fn[1000];
  int istep=0;
  double thrmin=1E6, thrmax=-1E6;

  int c=(int)string::npos;

  if (infile.is_open()) {
    cout << "Opened file " << enCalFileEntry->GetText() << endl;
    c=string(enCalFileEntry->GetText()).rfind('/');

    if (c!=string::npos)
      myDir=string(enCalFileEntry->GetText()).substr(0,c+1);
    
    //    cout << "Working directory is " << myDir << endl;

    enCalLogClass ec; 
    char settings[100];
    int nmod;
    int chanspermod;
    int mods[100]; 
    ec.readHeader(infile,settings,nmod,chanspermod,mods);
    scanStep *s;

    TList stepList;


    while (ec.getStep(infile, thr,fn)>=0) {
      if (thr>0) {
	s=new scanStep(thr, fn);
	if (thr<thrmin) thrmin=thr;
	if (thr>thrmax) thrmax=thr;
	
	
	stepList.Add(s);
	//delete s;
	istep++; 
      }
    }

    infile.close();

    sprintf(text,"Settings %s",settings);
    settingsLabel->SetText(text);

    sprintf(text,"Number of modules %d",nmod);
    nmodLabel->SetText(text);

    sprintf(text,"Channels per Module %d",chanspermod);
    chansPerModLabel->SetText(text);

    strcpy(text,"Modules serial numbers: ");
    for (int im=0; im<nmod; im++) {
      sprintf(sn,"sn%03x; ",mods[im]);
      strcat(text,sn);
    }
    modNumbersLabel->SetText(text);
    
    if (numberOfModules>0 && nmod!=numberOfModules) {
      cout << "Number of modules does not match!" << endl;
      error=1;

    } 
    if (error==0)
      numberOfModules=nmod;

    cout << "Number of modules is " << numberOfModules << endl;

    if (channelsPerModule>0 && chanspermod!=channelsPerModule) {
      cout << "Number of channels per module does not match!" << endl;
      error=1;
    } 
    if (error==0)
	channelsPerModule=chanspermod;
    
    if (string(detectorSettings)!=string(settings) && string(detectorSettings)!=string("none")){
      cout << "Detector settings do not match!" << endl;
      error=1;
    } 
    if (error==0) {
      strcpy(detectorSettings,settings);
      cout << "****************** detector settings are " << detectorSettings << endl;
    }
    if (string(modulesSerialNumbers)!=string(text) && string(modulesSerialNumbers)!=string("none")){
      cout << "Modules serial numbers do not match!" << endl;
      error=1;
    } 
    if (error==0) {
      
      for (int im=0; im<nmod; im++) {
	modSN[im]=mods[im];
      }
      strcpy(modulesSerialNumbers,text);

    }
    sprintf(text,"Energy %0.2f keV",enEntry->GetNumber());
    sprintf(name,"en%0.2fkeV",enEntry->GetNumber());

    if (istep<=1) {
      error=1;
      cout << "No threshold steps found! "<< istep << endl;
      return;
    }
    if (thrmin>=thrmax) {
      error=1;
      cout << "Threshold limits are bad: min "<< thrmin << " max " << thrmax << endl;
      return;
    }
    double delta=(thrmax-thrmin)/((double)(istep-1));
    //   previewH2=new TH2F(name,text,numberOfModules*channelsPerModule,-0.5,numberOfModules*channelsPerModule-0.5,istep,thrmin-0.5*delta,thrmax+0.5*delta);
    previewH2=new TH2F(name,text,numberOfModules*channelsPerModule,-0.5,numberOfModules*channelsPerModule-0.5,(thrmax-thrmin)/((int)delta),thrmin-0.5*((int)delta),thrmax+0.5*((int)delta));
    cout << thrmin << " " << thrmax << " " << delta << " " << previewH2->GetYaxis()->GetXmin() << " " << previewH2->GetYaxis()->GetXmax() << " " <<  previewH2->GetYaxis()->GetBinWidth(20) << endl;
    previewH2->SetStats(kFALSE);
    // cout << "created histo " << endl;
    previewH2->GetXaxis()->SetTitle("Channel Number");
    previewH2->GetYaxis()->SetTitle("Threshold");
    int data[numberOfModules*channelsPerModule];
    istep=0;
    //  TIter *it=new TIter(&stepList);
    //  it->Begin();
    s=(scanStep*) stepList.First();
    while (s) {
      //  cout << "spointer " << s << endl;
      // cout << "list " << istep <<  " fn " << s->getFileName() << " thr " << s->getValue() << endl;




      c=string(s->getFileName()).rfind('/');
      thr=s->getValue();
      // cout << "Opening file " << myDir+(s->getFileName()).substr(c+1,string::npos)+string(".raw") << endl;
      if ( fileIOStatic::readDataFile(myDir+(s->getFileName()).substr(c+1,string::npos)+string(".raw"),data,numberOfModules*channelsPerModule)>0) {
      // cout << "filling..." << endl;
	
	for (int i=0; i<numberOfModules*channelsPerModule; i++) {
	
	//	previewH2->Fill(i,s->getValue(),data[i] );
	  previewH2->SetBinContent(i+1,previewH2->GetYaxis()->FindBin(thr),data[i] );
	}
      }
      //  cout << "done" << endl;
      stepList.RemoveFirst();
      delete s;
      istep++;
      //s=(scanStep*) it->Next();
      s=(scanStep*) stepList.First();
    }
    // cout << "deleting iterator? " << endl;
    //  delete it;
    

    previewEnergy();

    goodData=1;


  } else
    cout << "Could not open file " << enCalFileEntry->GetText() << endl;



  
  editNewEnergy(-1);

  //  cout << "returning " << endl;
}



void enCalWizard::previewEnergy() {


  if (previewH2) {
    TCanvas *fCanvas = fEcanvas->GetCanvas();
    fCanvas->cd();
    previewH2->DrawCopy("colz");
    fCanvas->Update();
  } else cout << "energy histogram does not exist!" << endl;
}




void enCalWizard::chooseAction(Int_t id) {
  cout << "Action " << id << " chosen" << endl;

}

