# Are you on a Linux environment?! You will find yourself in
# an incredibly fast workflow.
SK = $(SKGCC)
TARGET = sys
OBJS = \
	main.o \
	write.o \
	clear.o

CFLAGS = -O2 -G0 -Wall -I $(SK)/lib/
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX = 1

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak
include $(SK)/include/general.mak