#ifndef SCAN_STEP_H
#define SCAN_STEP_H

#include <TObject.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;



class scanStep : public TObject {

 public:
  
  //  scanStep(double v, char *fn) : val(v), fname(fn) {};
  //  scanStep(double v, string fn) : val(v), fname(fn) {};
  scanStep(double v, char* fn) {val=v;  fname=string(fn);};


  ~scanStep(){};
      

  string  getFileName() {return fname;};
  double getValue(){return val;};


  string  setFileName(string fn) {fname=fn; return fname;};
  double setValue(double v){val=v; return val;};


  string Print() const{char tmp[2000]; sprintf(tmp,"%f \t \t %s",val, fname.c_str()); return string(tmp);  };

  void Print(Option_t *) const{ cout << Print(); };

  Bool_t IsEqual(TObject *obj) const{ return val == ((scanStep*)obj)->val; };
  Bool_t IsSortable() const { return kTRUE; };
  Int_t Compare(const TObject *obj) const{\
    if (val < ((scanStep*)obj)->val) return -1;				\
    else if (val > ((scanStep*)obj)->val) return 1;else return 0; \
  };






 private:
  double val;
  string fname;
 
  ClassDef(scanStep,0)  
};

#endif
