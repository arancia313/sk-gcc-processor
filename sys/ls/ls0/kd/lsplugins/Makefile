# FIRST WARNING: SECOND ARGUMENT OF MAIN SHOULD BE CHAR
SK = $(SKGCC)
TARGET = main_plugin
OBJS = \
	main_lsplugin.o
CFLAGS = -O2 -G0 -Wall -I $(SKGCC)/lib/
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX = 1

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak
include $(SK)/include/general.mak