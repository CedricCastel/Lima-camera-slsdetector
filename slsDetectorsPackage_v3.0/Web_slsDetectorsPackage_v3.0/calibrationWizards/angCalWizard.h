#include <TGFrame.h>

#include  <TGTextEntry.h>
#include <TGButton.h>

#include  "angularCalibration.h"


class TRootEmbeddedCanvas;
class TGButtonGroup;
class TGVerticalFrame;
class TGHorizontalFrame;
class TGLabel;
class TGNumberEntry;
class TH2F;
class TGComboBox;

class TGListBox;
class scanStep;

class   THStack;
class   TH1F;
class   TGraphErrors;
class  TGTextButton;
class TGLBContainer;
class angleConversionConstant;


#include <string>
using namespace std;

class angCalWizard : public TGMainFrame {
private:


  char *calFile;

   TRootEmbeddedCanvas *fScanCanvas;
   TRootEmbeddedCanvas *fModulecanvas;
   //TGButtonGroup *br;
   
   
   TGButtonGroup *advancementBG;
   TGVerticalFrame *vframe;
   TGHorizontalFrame *hpage;
   TGVerticalFrame *page;


   //calibration step related things!

   TGGroupFrame *scan1Frame;
   TGTextEntry *angCalFileEntry;

   
   TGComboBox *stepList;
	  //TGListBox *stepList;
   TGButtonGroup *stepListBG;

   TGLabel *nModLabel;
   TGLabel *maxModLabel;
   TGLabel *chansPerModLabel;
   TGTextEntry *angConvFileEntry;
   TGTextEntry *badChanFileEntry;
   TGTextEntry *ffFileEntry;
   TGCheckButton *angDirCB;
   TGNumberEntry *totalOffEntry;

   TGButtonGroup *plotModeBG;


   TGNumberEntry *angMinEntry;
   TGNumberEntry *angMaxEntry;
   TGButtonGroup *stepFitBG;


   TGButtonGroup *angCalFileBG;

   //module related things

   TGGroupFrame *moduleCalibrationFrame;
   TGCheckButton *centerCB;
   TGCheckButton *conversionCB;
   TGCheckButton *offsetCB;

   TGNumberEntry *centerEntry;
   TGNumberEntry *conversionEntry;
   TGNumberEntry *offsetEntry;

   TGLabel *centerLabel;
   TGLabel *conversionLabel;
   TGLabel *offsetLabel;
   TGButtonGroup *moduleFitBG;
   
   int numberOfModules;
   int maxNumberOfModules;
   int channelsPerModule;

   THStack *hsSteps;
   //   TH1F *h1FlatField;
   TH1F *previewH1, *processedH1, *ffH1;
   TH2F *scanH2;

   TGraphErrors *gStep;
   TGraphErrors *gModule;

   int error;
   int goodData;

   string myDir;
   TList *scanList;
  
   angularCalibration *myAngCal;

   angleConversionConstant *angOff;
   angleConversionConstant *fitAngOff;
   int *badChannelsList;
   int nBad;

   int *fitted;


   int iModule;

   TGGroupFrame *outFileFrame;
   TGTextEntry *outFileEntry;

public:
   angCalWizard(const TGWindow *p,UInt_t w,UInt_t h, char *s=NULL);
   void changePage(Int_t i);

   void addScanPage();
   void moduleCalibrationPage();
   void addOutFilePage(); 

   void angCalFileDialog();
   void loadAngCalFile();

   void outFileDialog(); 
   void saveAngConvFile(); 
/*    void previewEnCal(); */
/*    void previewEnergy(); */


/*    void chooseAction(Int_t); */


/*    void editNewEnergy(){editNewEnergy(-1);}; */
/*    void editNewEnergy(Int_t i); */
/*    void selectEnergy(Int_t i); */
   void editStepList(){editStepList(-1);};
   void editStepList(Int_t i);
   void setPlotMode(Int_t i);
   void previewStep();
   void previewSteps();
   void createStep(scanStep *s);
   void fitStep();
   void fitStep(scanStep *s, int save=0);
   void createRawDataHisto(string fname);
   void readAngularConversion(string fname);
   void readAngularConversion(){readAngularConversion(angConvFileEntry->GetText());};
   void readBadChans(){readBadChans(badChanFileEntry->GetText());};
   void readBadChans(string fname);
   void readFlatField(){readFlatField(ffFileEntry->GetText());};
   void readFlatField(string fname);
   void createProcessedDataHisto();
   void createFinalDataGraph(double pos);
   void setAngDir(){if (angDirCB->IsDown()) myAngCal->setDirection(-1); else myAngCal->setDirection(1);};
   void moduleNumberChanged();


/*    void addEnergy(); */
   void removeStep();
   
   void scrollModule(Int_t);
/*    void scrollEnergy(Int_t); */
/*    void writeCalibrationFile(); */
   
   


   ClassDef(angCalWizard,0)
};


