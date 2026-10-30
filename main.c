// Minimalistic code for the Home.
// and NO, i do not mean the stale minimalistic flat design
// that companies are pushing.
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include <string.h>
#include <pspgu.h>

#include <sk.h>
#include "main.h"

PSP_MODULE_INFO("sk-gcc", 0, 1, 1);

int main(int argc, char *argv[]) {
                            // Gotta wipe and init the screen this instant.
                            pspDebugScreenInit();
                            acorn("\n", NULL);
                            // Separator.
                            acorn(" ****************************************************************\n", NULL);
                            acorn(" * Arancia 3 SK-GCC Processor *                           Home  *\n", NULL);
                            acorn(" ******************************                                 *\n", NULL);
                            acorn(" *                                                              *\n", NULL);
                            acorn(" * Welcome to the Arancia 3 SK-GCC Processor for PSP.           *\n", NULL);
                            acorn(" * It requires ARK-4 A3 in order to run properly.               *\n", NULL);
                            acorn(" *                                                              *\n", NULL);
                            acorn(" ****************************************************************\n", NULL);
                            acorn(" * Instructions *                                               *\n", NULL);
                            acorn(" ****************                                               *\n", NULL);
                            acorn(" *                                                              *\n", NULL);
                            acorn(" * Triangle - Exit                                              *\n", NULL);
                            acorn(" * Cross    - Run Virtual Machine                               *\n", NULL);
                            acorn(" * Circle   - Activate host0:/                                  *\n", NULL);
                            acorn(" *                                                              *\n", NULL);
                            acorn(" ****************************************************************\n", NULL);
                            // Separator.
                            SceCtrlData pad;
                            sceCtrlSetSamplingCycle(0);
                            sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
                            while(1)
                            {
                                          sceCtrlReadBufferPositive(&pad, 1);
                                          if (pad.Buttons & PSP_CTRL_TRIANGLE)
                                          {
                                                        acornCls();
                                                        acorn("\n", NULL);
                                                        acorn(" Exiting..\n", NULL);
                                                        sceKernelExitGame();
                                          };
                                          if (pad.Buttons & PSP_CTRL_CROSS)
                                          {
                                                        sceKernelDelayThread(1000000);
                                                        run_vm();

                                          };
                                          if (pad.Buttons & PSP_CTRL_CIRCLE)
                                          {
                                                        ch0f();
                                          };
                                          sceDisplayWaitVblankStart();
                            }
}