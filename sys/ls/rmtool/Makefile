# Uninstall LS whenever you want. Just hand me the process.
SK = $(SKGCC)
TARGET = lsrmtool
OBJS = \
	main.o
CFLAGS = -O2 -G0 -Wall -I $(SKGCC)/lib/
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX = 1

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak
include $(SK)/include/general.mak