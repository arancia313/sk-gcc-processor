TARGET = sk-agcc
SKTARGET = sk-agcc
OBJS = main.o vm.o error.o

CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
EXTRA_TARGETS = EBOOT.PBP
BUILD_PRX = 1
PSP_EBOOT_TITLE = Arancia 3 SK-GCC Processor
PSP_EBOOT_ICON = resources/ICON0.PNG
all:
	$(Q)- mkdir ./SK_GCC_PROC
	$(Q)- cp ./EBOOT.PBP SK_GCC_PROC/EBOOT.PBP
	$(Q)- cp ./PARAM.SFO SK_GCC_PROC/PARAM.SFO
ripe:
	$(Q)make clean
	$(Q)rm -rf ./SK_GCC_PROC
PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
include ../sk-gcc/include/general.mak
skgcc  = $(sk_gcc)/lib/build.mak