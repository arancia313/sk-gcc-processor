#include <sk.h>
#include "../../main.h"
#include <pspsdk.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <string.h>
#include <pspiofilemgr.h>
#include "../../sys/binarybills.h"

PSP_MODULE_INFO("LSA3 Installer", 0, 1, 1);


static inline int loadmod(const char *path)
{
              SceUID thing = sceKernelLoadModule(path, 0, NULL);
              if (thing < 0)
              {
                            return thing;
              };
              int status = 0;
              int start = sceKernelStartModule(thing, 0, NULL, &status, NULL);
              if (start < 0)
              {
                            return start;
              };
              return thing;
}

int module_start(int argc, char **argv)
{
              pspDebugScreenInit();
              acorn("  ** LSA3 **                         Arancia 3 Technologies inc.\n", NULL);
              acorn("  **********\n", NULL);
              acorn("\n", NULL);
              acorn("  Press X to begin the installation.\n", NULL);
              acorn("\n", NULL);
              acorn("--------------------------------------------------------------------\n", NULL);
              SceCtrlData pad;
              while(1)
              {
                            sceCtrlReadBufferPositive(&pad, 1);
                            if (pad.Buttons & PSP_CTRL_CROSS)
                            {
                                          int fls = 1;
                                          if (fls == 1)
                                          {
                                          acorn("\n", NULL);
                                          acorn("  Loading %s modules...\n", HOST_PRESENCEFILE);
                                          int checkout = sceIoOpen(HOST_PRESENCEFILE, PSP_O_RDONLY, 0);
                                          if (checkout < 0)
                                          {
                                                        acorn("Could not open hostfile for writing. 0x%08X.\n", checkout);
                                                        acorn("Aborting.", NULL);
                                                        sceKernelDelayThread(10000000);
                                                        return 0;
                                          }
                                          else
                                          {
                                                        int checkout2;
                                                        // Close the previous file and just proceed with host0 writing.
                                                        sceIoClose(checkout);
                                                        acorn("  Writing LS files...\n", NULL);
                                                        fcopen(checkout2, "host0:/sys/ls/", "lsmain.", "A3", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777,
                                                        "LSmain\n"
                                                        "\n"
                                                        "Le Straodinarie: Master\n"
                                                        "Installation on host0:/.\n"
                                          );
                                                        binarybill();
                                                        acorn("  Writing is complete. Loading LSmenu.\n", NULL);
                                                        sceKernelDelayThread(5000000);
                                                        return 0;
                                          };
                                          }

                            };
                            if (pad.Buttons & PSP_CTRL_TRIANGLE)
                            {
                                          acornCls();
                                          acorn("\n", NULL);
                                          acorn(" Exiting...\n", NULL);
                                          sceKernelExitGame();
                            };
              };
}