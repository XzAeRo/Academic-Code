SRC=Informe2

all:
	pdflatex $(SRC).tex
	BIBINPUTS=. bibtex $(SRC)
	pdflatex $(SRC).tex
	pdflatex $(SRC).tex
	rm -rf *.out
	rm -rf *.log
	rm -rf *.dvi
	rm -rf *.aux
	rm -rf *.blg
	rm -rf *.bbl

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
