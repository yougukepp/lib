all:
	#make -C fig
	xelatex ppcc.tex
	xelatex ppcc.tex
	evince ppcc.pdf
clean:
	rm -rf *.aux *.idx *.log *.pdf *.toc *.out

distclean: clean
	make -C fig clean
