TARGET = lestraodinarie
OBJS = \
	main.o

CFLAGS = -Os -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX = 1

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak