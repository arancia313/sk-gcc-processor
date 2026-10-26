# First partition for Le Straodinarie.
SK = $(SKGCC)
TARGET = main
OBJS = \
	main.o \
	sys.o
CFLAGS = -O2 -G0 -Wall -I $(SK)/lib/
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX = 1

all:
	$(Q)$(MAKE) -C kd/lsplugins
PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak
include $(SK)/include/general.mak