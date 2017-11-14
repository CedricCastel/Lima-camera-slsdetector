#include <TGFrame.h>

class TRootEmbeddedCanvas;
class TGButtonGroup;
class TGVerticalFrame;
class TGHorizontalFrame;
class TGTextEntry;
class TGLabel;
class TGNumberEntry;
class TH2F;
class TGComboBox;
class TGCheckButton;

class   THStack;
class   TGraphErrors;
class energyCalibration;
class  TGTextButton;


#include <string>
using namespace std;

class enCalWizard : public TGMainFrame {
private:
   TRootEmbeddedCanvas *fEcanvas;
   TRootEmbeddedCanvas *fModulecanvas;
   TGButtonGroup *br;
   
   TGButtonGroup *advancementBG;
   TGButtonGroup *energyListBG;
   TGButtonGroup *newEnergyBG;
   TGButtonGroup *energyFitBG;
   TGButtonGroup *moduleFitBG;
   //TGButtonGroup *moduleCalibrationBG;
   
   TGComboBox *energyListCombo;

   Int_t iPage;
   Int_t iModule;
   Int_t iEnergy;
   TGVerticalFrame *vframe;
   TGVerticalFrame *page;
   TGHorizontalFrame *hpage;
   TGNumberEntry *enEntry;
   //   TGNumberEntry *moduleNumberEntry;

   
   TGNumberEntry *fitMinEntry;
   TGNumberEntry *fitMaxEntry;
   TGNumberEntry *pedestalEntry;
   TGNumberEntry *pedSlopeEntry;
   TGNumberEntry *flexEntry;
   TGNumberEntry *noiseEntry;
   TGNumberEntry *countsEntry;
   TGNumberEntry *csSlopeEntry;
   

   TGLabel *pedestalLabel;
   TGLabel *pedSlopeLabel;
   TGLabel *flexLabel;
   TGLabel *noiseLabel;
   TGLabel *countsLabel;
   TGLabel *csSlopeLabel;
   
   TGCheckButton *axisSignCheckButton;
   TGCheckButton *pedestalCheckButton;
   TGCheckButton *pedSlopeCheckButton;
   TGCheckButton *flexCheckButton;
   TGCheckButton *noiseCheckButton;
   TGCheckButton *countsCheckButton;
   TGCheckButton *csSlopeCheckButton;

   TGCheckButton *autoSaveCheckButton;
   TGTextButton *saveButton;

   TGTextEntry *enCalFileEntry;
   TGTextEntry *outFileEntry;
   TGLabel *settingsLabel;
   TGLabel *nmodLabel;
   TGLabel *chansPerModLabel;
   TGLabel *modNumbersLabel;
   
   
   TGLabel *gainLabel;
   TGLabel *offsetLabel;

   int numberOfModules;
   int channelsPerModule;
   char detectorSettings[100];
   char modulesSerialNumbers[1000];
   int modSN[100];
   TH2F *energyH2;
   TH2F *previewH2;
   THStack *previewH1;
   TGraphErrors *previewGraph;

   THStack *h1Modules[100];
   Double_t energies[100];


   int fileSaved[100];


   void createModuleHistos(int imod);
   void fitEnergy(int imod, int ien);
   void fitModule(int imod);

   int error;
   int goodData;




   string myDir;
   TList *energyList;
  
   TGGroupFrame *newEnergyFrame;
   TGGroupFrame *moduleCalibrationFrame;
   
   int mode;

   energyCalibration *myEnCal;

public:
   enCalWizard(const TGWindow *p,UInt_t w,UInt_t h);

   void addEnergyPage();
   void moduleCalibrationPage();

   void enCalFileDialog();
   void outFileDialog();
   void previewEnCal();
   void previewEnergy();


   void chooseAction(Int_t);

   void changePage(Int_t i);
   void editNewEnergy(){editNewEnergy(-1);};
   void editNewEnergy(Int_t i);
   void selectEnergy(Int_t i);
   void editEnergyList(){editEnergyList(-1);};
   void editEnergyList(Int_t i);
   void moduleNumberChanged();


   void addEnergy();
   void removeEnergy();
   
   void scrollModule(Int_t);
   void scrollEnergy(Int_t);
   void writeCalibrationFile();
   
   


   ClassDef(enCalWizard,0)
};


