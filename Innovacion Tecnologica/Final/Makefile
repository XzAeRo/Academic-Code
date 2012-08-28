SRC=informe_final

all:
	@echo Creando pdf...
	@pdflatex $(SRC).tex > .my_log || (cat .my_log && rm -rf .my_log && exit 1)
	@pdflatex $(SRC).tex > .my_log || (cat .my_log && rm -rf .my_log && exit 1)
	@rm -rf .my_log

clean:
	@echo "limpiando!"
	@rm -rf *.aux
	@rm -rf *.log
	@rm -rf *.out
	@rm -rf *.toc

distclean: clean
	@echo "eliminando pdf..."
	@rm -rf *.pdf

x: $(SRC).pdf
	xpdf $(SRC).pdf &> /dev/null &
o: $(SRC).pdf
	okular $(SRC).pdf &> /dev/null &
e: $(SRC).pdf
	evince $(SRC).pdf &> /dev/null &
