TARGET_MACHINE=20

SO=/home/pp/UPLINK_GPON/trunk/src/modules/bsp/bsp_uplink/user/libonu_bsp.so
PREFIX=/opt/toolchains/crosstools-mips-gcc-4.6-linux-3.4-uclibc-0.9.32-binutils-2.21/usr/bin/mips-unknown-linux-uclibc-

LFLAGS = -Wall -O2 -pedantic -std=c99
LD = $(PREFIX)gcc

CC=$(PREFIX)gcc
CFLAGS=-c $(LFLAGS) -I/home/pp/UPLINK_GPON/trunk/src/modules/bsp/bsp_uplink/user/

RM = rm -rf
STRIP = $(PREFIX)strip

all:i2c_test

i2c_test:clean i2c_test.c
	$(CC) $(CFLAGS) i2c_test.c -o i2c_test.o
	$(LD) $(LFLAGS) $(SO) i2c_test.o -o i2c_test
	$(STRIP) i2c_test
	mv i2c_test /home/pp/lrz/
	make clean
	
clean:
	$(RM) i2c_test *.so *.o

.PHONY : clean 


