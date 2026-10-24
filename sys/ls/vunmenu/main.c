#include <sk.h>
#include <pspkernel.h>
#include <pspsdk.h>
#include <pspdebug.h>
#include <pspiofilemgr.h>
#include <pspctrl.h>

#include "main.h"

PSP_MODULE_INFO("LSMenu", 0, 1, 1);

int module_start(int argc, char **argv)
{
              pspDebugScreenInit();
              acorn("  ** LSA3 **                          Arancia 3 Technologies inc.\n", NULL);
              acorn("  **********                                                     \n", NULL);
              acorn("                                                            Home \n", NULL);
              acorn("  Verifying presence of file...                                  \n", NULL);
              acorn("\n", NULL);
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
                            acorn("\n", NULL);
                            acorn("--------------------------------------------------------------------\n", NULL); acorn("\n", NULL);
                            acorn("--------------------------------------------------------------------\n", NULL);
              }
              SceCtrlData pad;
              while(1)
              {
                            sceCtrlReadBufferPositive(&pad, 1);
                            if (pad.Buttons & PSP_CTRL_TRIANGLE)
                            {
                                          acornCls();
                                          acorn("\n", NULL);
                                          acorn(" Exiting...", NULL);
                                          return 0;
                            }
              }
}