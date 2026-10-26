# Installer for LS. "Should be ready at any minute".
SK = $(SKGCC)
TARGET = a3LSinstaller
OBJS = \
	main.o
CFLAGS = -O2 -G0 -Wall -I $(SKGCC)/lib/
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX = 1

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak
include $(SK)/include/general.mak