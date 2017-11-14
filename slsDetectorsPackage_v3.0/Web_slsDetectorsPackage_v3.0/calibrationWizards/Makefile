
SRC=TSlsDetector.cpp enCalWizard.cpp energyCalibration.cpp energyConversion.cpp angCalWizard.cpp angularConversionStatic.cpp angularCalibration.cpp enCalDict.cpp 
INCS=TSlsDetector.h enCalWizard.h  enCalLogClass.h fileIOStatic.h energyCalibration.h energyConversion.h sls_detector_defs.h scanStep.h angularConversionStatic.h angCalLogClass.h angularCalibration.h angCalWizard.h badChannelCorrections.h enCalLinkDef.h 


MAINEN=energyCalibrationWizard.cpp
MAINANG=angularCalibrationWizard.cpp

DESTDIR?=../bin

all: versioning $(DESTDIR)/energyCalibrationWizard $(DESTDIR)/angularCalibrationWizard

doc:
	cd manual && make DESTDIR=$(DESTDIR)

htmldoc:
	cd manual && make html DESTDIR=$(DESTDIR)

enCalDict.cpp: $(INCS)
	rootcint -f enCalDict.cpp -c $(INCS) 	

$(DESTDIR)/energyCalibrationWizard: $(SRC) $(MAINEN)
	@echo `tput setaf 6;	./updateGitVersion.sh; tput sgr0;`
	g++ -DMYROOT `root-config --cflags --glibs` -lMinuit -o energyCalibrationWizard $(SRC)  $(MAINEN)
	mv energyCalibrationWizard $(DESTDIR)	

$(DESTDIR)/angularCalibrationWizard: $(SRC) $(MAINANG)
	@echo `tput setaf 6;	./updateGitVersion.sh; tput sgr0;`
	g++ -DMYROOT `root-config --cflags --glibs` -lMinuit -o angularCalibrationWizard $(SRC)  $(MAINANG)
	mv angularCalibrationWizard $(DESTDIR)
	
clean:
	rm -f enCalDict.cpp energyCalibrationWizard angularCalibrationWizard
	cd manual && make clean

define colorecho
      @tput setaf 6
      @echo $1
      @tput sgr0
endef
	
	
versioning: 
	$(call colorecho,`./updateGitVersion.sh`)

	
