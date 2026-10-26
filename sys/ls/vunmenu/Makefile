# Small Makefile? Do you think this is a STANDARD MALKEFILE?!
SK = $(SKGCC)
TARGET = lsmenu
OBJS = \
	main.o
CFLAGS = -O2 -G0 -Wall -I $(SK)/lib/
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX = 1

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak
include $(SK)/include/general.mak