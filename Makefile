TARGET = proc
SKTARGET = proc
OBJS = \
	main.o \
	vm.o \
	error.o

CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
EXTRA_TARGETS = EBOOT.PBP
BUILD_PRX = 1
LIBS = -lpspgu -lpspdisplay -lpspdebug -lpspsdk
PSP_FW_VERSION = 661
PSP_EBOOT_TITLE = Arancia 3 SK-GCC Processor
PSP_EBOOT_ICON = resources/ICON0.PNG
all: build
	$(Q) mkdir ./SK_GCC_PROC
	$(Q) cp ./EBOOT.PBP SK_GCC_PROC/EBOOT.PBP
	$(Q) cp ./PARAM.SFO SK_GCC_PROC/PARAM.SFO
	@echo "Build Done."
build:
	$(Q)$(MAKE) -C sys
	$(Q)$(MAKE) -C sys/ls
ripe:
	$(Q)$(MAKE) -C sys clean
	$(Q)$(MAKE) -C sys/ls clean
	$(Q)make clean
	$(Q)rm -rf ./SK_GCC_PROC
	$(Q)rm -rf int.A3
	$(Q)rm -rf test.A3
	$(Q)rm -rf sys/list/cv.A3
	$(Q)rm -rf sys/ls/lshl.A3
	$(Q)rm -rf sys/ls/lsmain.A3
PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
include ../sk-gcc/include/general.mak
skgcc  = $(sk_gcc)/lib/build.mak