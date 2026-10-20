// Minimalistic code for the Home.

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include <string.h>
#include <pspgu.h>

#include "./sk-gcc/lib/sk.h"
#include "main.h"

PSP_MODULE_INFO("sk-gcc", 0, 1, 1);

int main(int argc, char *argv[]) {
                            // Gotta wipe and init the screen this instant.
                            pspDebugScreenInit();
                            pspDebugScreenPrintf("\n");
                            // Separator.
                            pspDebugScreenPrintf(" ****************************************************************\n");
                            pspDebugScreenPrintf(" * Arancia 3 SK-GCC Processor *                           Home  *\n");
                            pspDebugScreenPrintf(" ******************************                                 *\n");
                            pspDebugScreenPrintf(" *                                                              *\n");
                            pspDebugScreenPrintf(" * Welcome to the Arancia 3 SK-GCC Processor for PSP.           *\n");
                            pspDebugScreenPrintf(" * It requires ARK-4 A3 in order to run properly.               *\n");
                            pspDebugScreenPrintf(" *                                                              *\n");
                            pspDebugScreenPrintf(" ****************************************************************\n");
                            pspDebugScreenPrintf(" * Instructions *                                               *\n");
                            pspDebugScreenPrintf(" ****************                                               *\n");
                            pspDebugScreenPrintf(" *                                                              *\n");
                            pspDebugScreenPrintf(" * Triangle - Exit                                              *\n");
                            pspDebugScreenPrintf(" * Cross    - Run Virtual Machine                               *\n");
                            pspDebugScreenPrintf(" *                                                              *\n");
                            pspDebugScreenPrintf(" ****************************************************************\n");
                            // Separator.
                            SceCtrlData pad;
                            sceCtrlSetSamplingCycle(0);
                            sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
                            while(1) {
                                          sceCtrlReadBufferPositive(&pad, 1);
                                          if (pad.Buttons & PSP_CTRL_TRIANGLE) {
                                                        acornCls();
                                                        acorn("\n", NULL);
                                                        acorn(" Exiting..\n", NULL);
                                                        sceKernelExitGame();
                                          };
                                          if (pad.Buttons & PSP_CTRL_CROSS) {
                                                        sceKernelDelayThread(1000000);
                                                        run_vm();

                                          };
                                          sceDisplayWaitVblankStart();
                            }
}