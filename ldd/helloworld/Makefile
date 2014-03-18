# If KERNELRELEASE is defined, we've been invoked from the
# kernel build system and can use its language.
ifneq ($(KERNELRELEASE),)
	obj-m := hello.o 
# Otherwise we were called directly from the command
# line; invoke the kernel build system.
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd) 

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean: 
	rm -rvf hello.ko hello.mod.o hello.o hello.mod.c modules.order Module.symvers .hello.ko.cmd .hello.o.cmd .hello.mod.o.cmd .tmp_versions/
endif 
