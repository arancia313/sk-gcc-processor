#include "../../../sk-gcc/lib/sk.h"
#include <pspkernel.h>
#include <pspsdk.h>
#include <pspdebug.h>
#include <pspiofilemgr.h>
#include <pspctrl.h>

#include "main.h"

PSP_MODULE_INFO("LSMenu", 0, 1, 1);

int main(int argc, char **argv)
{
              pspDebugScreenInit();
              acorn("  ** LSA3 **                          Arancia 3 Technologies inc.\n", NULL);
              acorn("  **********                                                     \n", NULL);
              acorn("                                                            Home \n", NULL);
              acorn("  Verifying presence of file...                                  \n", NULL);
              sceKernelDelayThread(1000000);
              int checkout = sceIoOpen("host0:/sys/ls/lshl.A3", PSP_O_RDONLY, 0);
              if (checkout < 0)
              {
                            acorn("  Run Failed: 0x%08X\n", checkout);
                            sceKernelDelayThread(1000000);
                            return 0;
              }
              else
              {
                            acorn("  Welcome to Le Straodinarie.\n", NULL);
              }
}