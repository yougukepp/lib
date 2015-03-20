TARGET_MACHINE = __BCM683XX__
#TARGET_MACHINE = __X86_64__

ifeq ($(TARGET_MACHINE), __BCM683XX__)
    PREFIX=/opt/toolchains/crosstools-mips-gcc-4.6-linux-3.4-uclibc-0.9.32-binutils-2.21/usr/bin/mips-unknown-linux-uclibc-
else
    PREFIX=
endif 

LFLAGS = -lpthread -Wall -O2 -pedantic -std=c99 -D_BSD_SOURCE -D$(TARGET_MACHINE)

CFLAGS = -c $(LFLAGS)

RM = rm -rf

LD = $(PREFIX)gcc
CC = $(PREFIX)gcc
STRIP = $(PREFIX)strip


all:nand_test

nand_test: clean nand_test.c
	@$(CC) $(LFLAGS) nand_test.c -o nand_test
	@echo "CC       nand_test.c"
	@$(STRIP) nand_test
	@echo "strip    nand_test"
	#./nand_test 2048 130 1000 2 ./nand.test

tar:nand_test
	@tar cf out.tar ./nand_test ./run.sh && mv out.tar /home/pp/68380/
	@echo "TAR & MOVE TO /home/pp/68380"


clean:
	@$(RM) nand_test
	@$(RM) nand.test
	@echo "CLEAN"

.PHONY: index all tar clean

