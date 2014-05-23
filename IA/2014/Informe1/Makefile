SRC=Informe1

all:
	pdflatex $(SRC).tex
	BIBINPUTS=. bibtex $(SRC)
	pdflatex $(SRC).tex
	pdflatex $(SRC).tex
	rm -rf *.{out,log,dvi,aux,blg,bbl}

clean:
	rm -rf *.out
	rm -rf *.log
	rm -rf *.dvi
	rm -rf *.aux
	rm -rf *.blg
	rm -rf *.bbl


distclean:
	rm -rf $(SRC).pdf
x:
	xpdf $(SRC).pdf
