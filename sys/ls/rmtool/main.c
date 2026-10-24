#include <sk.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspsdk.h>
#include <pspctrl.h>
#include <pspiofilemgr.h>

#include <stdio.h>
#include <string.h>

PSP_MODULE_INFO("LSA3 Uninstaller", 0, 1 ,1);

int main(int argc, char *argv)
{
              pspDebugScreenInit();
              acorn("  ** LSA3 **                         Arancia 3 Technologes inc.  \n", NULL);
              acorn("  **********\n", NULL);
              acorn("\n", NULL);
              acorn("  Press X To begin radical LS removal.\n", NULL);
              SceCtrlData pad;
              while(1)
              {
                            sceCtrlReadBufferPositive(&pad, 1);
                            if (pad.Buttons & PSP_CTRL_CROSS)
                            {
                                          acorn("\n", NULL);
                                          acorn("  Loading host0:/ modules...\n", NULL);
                                          int checkout = sceIoOpen("host0:/host0.txt", PSP_O_RDONLY, 0);
                                          if (checkout < 0)
                                          {
                                                        acorn("  Could not open file for writing, it could be absent. 0x%08X\n", checkout);
                                                        acorn("  Aborting.\n", NULL);
                                                        sceKernelDelayThread(5000000);
                                                        return 0;
                                          }
                                          else
                                          {
                                                        acorn("  Physical removal...\n", NULL);
                                                        int checkout2 = sceIoOpen("host0:/sys/ls/lshl.A3", PSP_O_RDONLY, 0);
                                                        if (checkout2 < 0)
                                                        {
                                                                      acorn("  File not found, aborting. 0x%08X.\n", checkout2);
                                                                      sceKernelDelayThread(1000000);
                                                                      return 0;
                                                        }
                                                        else
                                                        {
                                                                      sceIoClose(checkout2);
                                                                      sceIoRemove("host0:/sys/ls/lshl.A3");
                                                        };
                                                        int checkout3 = sceIoOpen("host0:/sys/ls/lsmain.A3", PSP_O_RDONLY, 0);
                                                        if (checkout3 < 0)
                                                        {
                                                                      acorn("  File not found, aborting. 0x%08X.\n", checkout3);
                                                                      sceKernelDelayThread(1000000);
                                                                      return 0;
                                                        }
                                                        else
                                                        {
                                                                      sceIoClose(checkout3);
                                                                      sceIoRemove("host0:/sys/ls/lsmain.A3");
                                                        };
                                                        sceIoClose(checkout);
                                                        acorn("  Le Straodnarie was radically uninstalled.\n", NULL);
                                                        sceKernelDelayThread(5000000);
                                                        return 0;
                                          };
                            }
              }
}