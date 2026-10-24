#include <pspsdk.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include <stdio.h>
#include <string.h>
#include <sk.h>

int sys(int argc, char *argv)
{
              unsigned char *syscon[]  = {0x00, 0x01, 0x00, 0x00, 0x99, 0x11};
              unsigned char *syscon2[] = {0x00, 0x00, 0x22, 0x44, 0x11, 0x66};
              unsigned char *syscon3[] = {0x00000000, 0x04820284, 0x93938203};
              unsigned char *syscon4[] = {0x44334433, 0x33333333, 0x22429405};
              SPLset(syscon, syscon2, syscon3, syscon4);
}