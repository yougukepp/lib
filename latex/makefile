all:
	xelatex temple.tex
	xelatex temple.tex
	evince temple.pdf &
clean:
	rm -rf *.aux *.idx *.log *.pdf *.toc *.out

distclean: clean
	make -C fig clean
