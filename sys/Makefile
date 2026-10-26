# Are you on a Linux environment?! You will find yourself in
# an incredibly fast workflow.
TARGET = sys
OBJS = \
	main.o \
	write.o \
	clear.o

CFLAGS = -O2 -G0 -Wall -I ../sk-gcc/lib/
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX = 1

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak
SK = $(SKGCC)
include $(SK)/include/general.mak