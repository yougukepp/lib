#TARGET_MACHINE=mdu
TARGET_MACHINE=20

PREFIX=/opt/toolchains/crosstools-mips-gcc-4.6-linux-3.4-uclibc-0.9.32-binutils-2.21/usr/bin/mips-unknown-linux-uclibc-

LFLAGS = -Wall -O2 -pedantic -std=c99
RM = rm -rf

LD = $(PREFIX)gcc
STRIP = $(PREFIX)strip

ifeq ($(TARGET_MACHINE), mdu)
    LFLAGS+=-I/home/pp/MDU_BCM68380/trunk/modules/bsp/mdu/user/
    SO=/home/pp/MDU_BCM68380/trunk/modules/bsp/mdu/user/libonu_bsp.so
else
    LFLAGS+=-I/home/pp/UPLINK_GPON/trunk/src/modules/bsp/bsp_uplink/user/
    SO=/home/pp/UPLINK_GPON/trunk/src/modules/bsp/bsp_uplink/user/libonu_bsp.so
endif 

all:i2c_test

i2c_test:clean i2c_test.c
	cp $(SO) ./
	$(LD) $(LFLAGS) libonu_bsp.so i2c_test.c -o i2c_test
	$(STRIP) i2c_test
	#mv i2c_test /home/pp/lrz/
	
clean:
	$(RM) i2c_test *.so

.PHONY : clean 


