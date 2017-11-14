DESTDIR?=../docs

all: $(DESTDIR)/pdf/angularCalibrationHowTo.pdf  $(DESTDIR)/pdf/energyCalibrationHowTo.pdf 

$(DESTDIR)/pdf/angularCalibrationHowTo.pdf: angularCalibrationHowTo.tex ancCal.tex
	$(shell test -d $(DESTDIR) || mkdir -p $(DESTDIR))
	$(shell test -d $(DESTDIR)/pdf || mkdir -p $(DESTDIR)/pdf)
	latex angularCalibrationHowTo.tex
	latex angularCalibrationHowTo.tex
	dvips -o angularCalibrationHowTo.ps angularCalibrationHowTo.dvi
	ps2pdf angularCalibrationHowTo.ps angularCalibrationHowTo.pdf
	mv angularCalibrationHowTo.pdf $(DESTDIR)/pdf/angularCalibrationHowTo.pdf


$(DESTDIR)/pdf/energyCalibrationHowTo.pdf: energyCalibrationHowTo.tex enCal.tex
	$(shell test -d $(DESTDIR) || mkdir -p $(DESTDIR))
	$(shell test -d $(DESTDIR)/pdf || mkdir -p $(DESTDIR)/pdf)
	latex energyCalibrationHowTo.tex
	latex energyCalibrationHowTo.tex
	dvips -o energyCalibrationHowTo.ps energyCalibrationHowTo.dvi
	ps2pdf energyCalibrationHowTo.ps energyCalibrationHowTo.pdf
	mv energyCalibrationHowTo.pdf $(DESTDIR)/pdf/energyCalibrationHowTo.pdf

html: $(DESTDIR)/html/calibrationWizardsHowTo

$(DESTDIR)/html/calibrationWizardsHowTo: calibrationWizardsHowTo.tex ancCal.tex enCal.tex installation.tex
	$(shell test -d $(DESTDIR) || mkdir -p $(DESTDIR))
	$(shell test -d $(DESTDIR)/html || mkdir -p $(DESTDIR)/html)
	$(shell test -d $(DESTDIR)/html/calibrationWizardsHowTo && rm -r  $(DESTDIR)/html/calibrationWizardsHowTo)
	latex calibrationWizardsHowTo.tex
	latex2html -split 4 calibrationWizardsHowTo.tex
	mv calibrationWizardsHowTo $(DESTDIR)/html
clean:
	rm -rf *.pdf *.dvi *.ps *.aux *.log *toc calibrationWizardsHowTo
