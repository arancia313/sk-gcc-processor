#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <string.h>

PSP_MODULE_INFO("sk-gcc", 0, 1, 1);

int main(int argc, char *argv[]) {
                            // Gotta wipe and init the screen this instant.
                            pspDebugScreenInit();
                            pspDebugScreenPrintf("****************************************************************\n");
                            pspDebugScreenPrintf("* Arancia 3 SK-GCC Processor *                           Home  *\n");
                            pspDebugScreenPrintf("******************************                                 *\n");
                            pspDebugScreenPrintf("*                                                              *\n");
                            pspDebugScreenPrintf("* Welcome to the Arancia 3 SK-GCC Processor for PSP.           *\n");
                            pspDebugScreenPrintf("* It requires ARK-4 A3 in order to run properly.               *\n");
                            pspDebugScreenPrintf("*                                                              *\n");
                            pspDebugScreenPrintf("****************************************************************\n");
                            pspDebugScreenPrintf("* Instructions *                                               *\n");
                            pspDebugScreenPrintf("****************                                               *\n");
                            pspDebugScreenPrintf("*                                                              *\n");
                            pspDebugScreenPrintf("* Triangle - Exit                                              *\n");
                            pspDebugScreenPrintf("* Cross    - Run Virtual Machine                               *\n");
                            pspDebugScreenPrintf("* Circle   - Activate CELBLOCK Utility (Requires ARK-4 A3)     *\n");
                            pspDebugScreenPrintf("*                                                              *\n");
                            pspDebugScreenPrintf("****************************************************************\n");
                            SceCtrlData pad;
                            sceCtrlSetSamplingCycle(0);
                            sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
                            while(1) {
                                          sceCtrlReadBufferPositive(&pad, 1);
                                          if (pad.Buttons & PSP_CTRL_TRIANGLE) {
                                                        pspDebugScreenPrintf("\n");
                                                        pspDebugScreenPrintf("Exiting..\n");
                                                        sceKernelExitGame();
                                          };
                                          if (pad.Buttons & PSP_CTRL_CROSS) {
                                                        run_vm();

                                          };
                                          sceDisplayWaitVblankStart();
                            }
}