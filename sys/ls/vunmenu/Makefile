# Small Makefile? Do you think this is a STANDARD MALKEFILE?!
TARGET = lsmenu
OBJS = \
	main.o
CFLAGS = -O2 -G0 -Wall -I ../../../sk-gcc/lib/
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX = 1

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak