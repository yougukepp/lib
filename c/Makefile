include buildvars

all:clean test
	./test -lHyC

test:libHyC.a
	$(LD) main.c -o test libHyC.a

libHyC.a:
	mkdir ./lib
	${MAKE} -C taocp
	${MAKE} -C sicp
	${MAKE} -C myself
	$(AR) libHyC.a ./lib/*

printVars:
	@echo ${ROOT_DIR}
	@echo ${INC}
	@echo ${CC}
	@echo ${LD}

clean:
	${RM} *.stackdump
	${RM} test*
	${RM} *.o
	${RM} *.so
	${RM} *.a
	${RM} ./lib
	${MAKE} -C taocp clean
	${MAKE} -C sicp clean
	${MAKE} -C myself clean

