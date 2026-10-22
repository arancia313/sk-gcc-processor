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

.PHONY: build ls0

all: build ls0
	$(Q) - mkdir ./SK_GCC_PROC
	$(Q) - cp ./EBOOT.PBP SK_GCC_PROC/EBOOT.PBP
	$(Q) - cp ./PARAM.SFO SK_GCC_PROC/PARAM.SFO
	@echo "Build Done."
build:
	$(Q)$(MAKE) -C sys
	$(Q)$(MAKE) -C sys/ls
	$(Q)$(MAKE) -C sys/ls/vunmenu
	$(Q)$(MAKE) -C sys/ls/rmtool
ls0:
	$(Q)$(MAKE) -C sys/ls/ls0
	$(Q)mkdir -p ls0/
	$(Q)mkdir -p ls0/kd
	$(Q)mkdir -p ls0/dumps
	$(Q)cp sys/ls/ls0/*.prx ls0/
	$(Q)cp sys/ls/ls0/kd/lsplugins/*.prx ls0/
	$(Q)cp sys/ls/ls0/*.o ls0/
	$(Q)cp sys/ls/ls0/kd/lsplugins/*.o ls0/
	$(Q)cp sys/ls/a3LSinstaller.prx ls0/
	$(Q)cp sys/ls/rmtool/lsrmtool.prx ls0/
	$(Q)cp sys/ls/vunmenu/lsmenu.prx ls0/
	$(Q)mv ls0/*.prx ls0/kd/
	$(Q)mv ls0/*.o ls0/dumps/
ripe:
	$(Q)$(MAKE) -C sys clean
	$(Q)$(MAKE) -C sys/ls clean
	$(Q)$(MAKE) -C sys/ls/vunmenu clean
	$(Q)$(MAKE) -C sys/ls/rmtool clean
	$(Q)$(MAKE) -C sys/ls/ls0 clean
	$(Q)$(MAKE) -C sys/ls/ls0/kd/lsplugins clean
	$(Q)make clean
	$(Q)rm -rf ./SK_GCC_PROC
	$(Q)rm -rf int.A3
	$(Q)rm -rf test.A3
	$(Q)rm -rf sys/list/cv.A3
	$(Q)rm -rf sys/ls/lshl.A3
	$(Q)rm -rf sys/ls/lsmain.A3
	$(Q)rm -rf ./ls0
PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
include ../sk-gcc/include/general.mak
skgcc  = $(sk_gcc)/lib/build.mak