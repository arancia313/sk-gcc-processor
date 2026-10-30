#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include <string.h>
#include <pspgu.h>
#include <pspiofilemgr.h>

#include <sk.h>
#include "main.h"

void ch0f(void)
{
              acornCls();
              acorn("\n", NULL);
              acorn("  Obtaining host0:/..\n", NULL);
              acorn("--------------------------------------------------------------------\n", NULL);
              sceKernelDelayThread(1000000);
              int checkouthost0f = sceIoOpen("host0:/host0.txt", PSP_O_RDONLY, 0);
              if (checkouthost0f < 0)
              {
                            errorhost();
              } else
              {
                            acorn(" Activating host0:/..\n", NULL);
                            int host0 = 1;
                            acorn(" Activation complete.\n", NULL);
                            sceKernelDelayThread(1000000);
                            main();
              }
}