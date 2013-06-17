include buildvars

all:clean test
	./test

test:lib.so
	gcc -I${INC} lib.so main.c -o test

lib.so:
	${MAKE} -C taocp
	${MAKE} -C sicp
	${MAKE} -C myself
	${LD} lib/* -o lib.so

printVars:
	@echo ${ROOT_DIR}
	@echo ${INC}
	@echo ${CC}
	@echo ${LD}

clean:
	${RM} *.stackdump
	${RM} *.exe
	${RM} *.o
	${RM} *.so
	${RM} ./lib/*
	${MAKE} -C taocp clean
	${MAKE} -C sicp clean
	${MAKE} -C myself clean

