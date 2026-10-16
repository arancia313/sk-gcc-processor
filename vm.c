#include <stdio.h>
#include <pspkernel.h>
#include <pspsdk.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <string.h>
#include <pspgu.h>
// Prepare sk-gcc toolchain and main.h files!

#include "./sk-gcc/lib/sk.h"
#include "main.h"

void run_vm(void) {
              int fd;
              pspDebugScreenClear();
              acorn("\n", NULL);
              pspDebugScreenPrintf(" ****************************************************************\n");
              pspDebugScreenPrintf(" * Virtual Machine *   Target: Memory Stick * Processing files  *\n");
              pspDebugScreenPrintf(" *******************                        *                   *\n");
              pspDebugScreenPrintf(" *                                                              *\n");
              pspDebugScreenPrintf(" * Processing Virtual Machine files. Please wait.               *\n");
              pspDebugScreenPrintf(" *                                                              *\n");
              pspDebugScreenPrintf(" ****************************************************************\n");
              sceIoMkdir("ms0:/PSP/sk-gcc", 0777);
              fd = sceIoOpen(MS0_COMUNIC_FILE, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
              if (fd >= 0) {char *content = "SK-GCC: log from SK-GCC Processor"; sceIoWrite(fd, content, strlen(content)); sceIoClose(fd);};
              pspDebugScreenPrintf(" * Virtual Machine #2 *   Target: flash4 * Processing Files #2  *\n");
              pspDebugScreenPrintf(" **********************                  *                      *\n");
              pspDebugScreenPrintf(" *                                                              *\n");
              pspDebugScreenPrintf(" * File process completed. Setting up flash4 to start VM.       *\n");
              pspDebugScreenPrintf(" * Do not exit the software during setup, as you may lose or co *\n");
              pspDebugScreenPrintf(" * -rrupt several data.                                         *\n");
              pspDebugScreenPrintf(" *                                                              *\n");
              pspDebugScreenPrintf(" ****************************************************************\n");
              sceIoMkdir(FLASH4_SAVE_PATH, 0777);
              fd = sceIoOpen(FLASH4_COMUNIC_FILE, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
              if (fd >= 0) {char *content2 = "SK-GCC: log from SK-GCC Processor"; sceIoWrite(fd, content2, strlen(content2)); sceIoClose(fd);};
              pspDebugScreenPrintf("\n");
              pspDebugScreenPrintf(" Starting VM..\n");
              pspDebugScreenClear();
              pspDebugScreenPrintf("\n");
              pspDebugScreenPrintf(" Verifying presence of %s...\n", MS0_FLASH4_FILE);
              int callfile = sceIoOpen(MS0_FLASH4_FILE, PSP_O_RDONLY, 0);
              if (callfile < 0)
              {
                            pspDebugScreenPrintf(" The file is non-existent: 0x%08X\n", callfile);
                            pspDebugScreenPrintf(" Aborting.\n");
                            sceKernelDelayThread(1000000);
                            main();
              } else {
                            pspDebugScreenPrintf(" Virtual Machine has started.\n");
                            pspDebugScreenPrintf(" File called out: %s.\n", MS0_FLASH4_FILE);
                            sceIoClose(callfile);
                            int checkhostfile = sceIoOpen(HOST_PRESENCEFILE, PSP_O_RDONLY, 0);
                            if (checkhostfile < 0)
                            {
                                          acorn(" Host file is absent. 0x%08X", checkhostfile);
                            } else
                            {
                                          acorn(" File called out: %s", HOST_PRESENCEFILE);
                                          sceIoClose(checkhostfile);
                            };
                            sceKernelDelayThread(1000000);
                            acornCls();
                            // Separator.
                            acorn("\n", NULL);
                            acorn(" *****************************************************************\n", NULL);
                            acorn(" * Virtual Machine *                                       Home  *\n", NULL);
                            acorn(" *******************                                             *\n", NULL);
                            acorn(" *                                                               *\n", NULL);
                            acorn(" * Virtual Machine is running.                                   *\n", NULL);
                            acorn(" * Waiting for connections up there.                             *\n", NULL);
                            acorn(" *                                                               *\n", NULL);
                            acorn(" *****************************************************************\n", NULL);
                            acorn(" *                                                               *\n", NULL);
                            acorn(" * If the VM is running on a testing environment like PSPLINK,   *\n", NULL);
                            acorn(" * The VM may sometimes interfere with connecting to another     *\n", NULL);
                            acorn(" * unit, which is probably NOT what you want. It's still able to *\n", NULL);
                            acorn(" * interact with PSPLINK's host0:/, though.                      *\n", NULL);
                            acorn(" *                                                               *\n", NULL);
                            acorn(" *****************************************************************\n", NULL);
                            // Separator.
                            acorn("\n", NULL);
                            acorn(" Files called out for VM:\n", NULL);
                            acorn("\n", NULL);
                            int checkout = sceIoOpen(MS0_FLASH4_FILE, PSP_O_RDONLY, 0);
                            if (checkout < 0)
                            {
                                          acorn(" * Could not open called file. 0x%08X.\n", checkout);
                                          sceKernelDelayThread(1000000);
                                          errorms();

                            } else
                            {
                                          acorn(" * Called: %s\n", MS0_FLASH4_FILE);
                                          sceIoClose(checkout);
                            };
                            int checkout2 = sceIoOpen(MS0_COMUNIC_FILE, PSP_O_RDONLY, 0);
                            if (checkout2 < 0)
                            {
                                          acorn(" * Could not open called file. 0x%08X.\n", checkout2);
                                          sceKernelDelayThread(1000000);
                                          errorms();
                            } else
                            {
                                          acorn(" * Called: %s\n", MS0_COMUNIC_FILE);
                                          sceIoClose(checkout2);
                            };
                            int checkout3 = sceIoOpen(HOST_PRESENCEFILE, PSP_O_RDONLY, 0);
                            if (checkout3 < 0)
                            {
                                          acorn(" * Could not open called file. 0x%08X.\n", checkout3);
                            } else
                            {
                                          acorn(" * Called: %s", HOST_PRESENCEFILE);
                                          sceIoClose(checkout3);
                            };

              };
}