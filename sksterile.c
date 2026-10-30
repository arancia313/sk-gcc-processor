#include <sk.h>
#include <pspsdk.h>
#include <pspkernel.h>
#include <pspiofilemgr.h>
#include <pspctrl.h>
#include <pspdebug.h>
#include <stdio.h>
#include <string.h>

int skmenu(int argc, char *argv)
{
              pspDebugScreenInit();
              acorn("\n", NULL);
              acorn("  sk-gcc menu\n", NULL);
              acorn("--------------------------------------------------------------------\n", NULL);
              acorn("\n", NULL);
              acorn("  This is the SK-GCC menu. You can use it for deleting old SK-GCC\n", NULL);
              acorn("  data, and such.\n", NULL);
              acorn("  You can press Triangle to exit.\n", NULL);
              acorn("\n", NULL);
              acorn("  Triangle - Exit\n", NULL);
}