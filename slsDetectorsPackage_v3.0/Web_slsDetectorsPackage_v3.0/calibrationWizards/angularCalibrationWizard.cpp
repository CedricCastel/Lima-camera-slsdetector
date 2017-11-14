#include <TApplication.h>
#include <TColor.h>
#include <TStyle.h>
#include <TROOT.h>

#include "angCalWizard.h"
#include "TSlsDetector.h"

void example(char *s) {
   // Popup the GUI...
  angCalWizard *mf=new angCalWizard(gClient->GetRoot(),800,800,s);
//    mf->addEnergyPage();
//    mf->moduleCalibrationPage();
//    mf->changePage(-1);
}

int main(int argc, char **argv) {
   TApplication theApp("App",&argc,argv);

   TSlsDetector::rootLogon();
   cout << argc << endl;

   for (int i=0; i<argc ; i++)
     cout << argv[i] << endl;
   
   if (argc>1)
     example(argv[1]);
   else
     example(NULL);


   theApp.Run();
   return 0;
}
