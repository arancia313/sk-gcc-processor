#include <stdio.h>
#include <pspkernel.h>
#include <pspsdk.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <sk-gcc.h>

void run_vm(void) {
              int fd;
              pspDebugScreenClear();
              pspDebugScreenPrintf("****************************************************************\n");
              pspDebugScreenPrintf("* Virtual Machine *   Target: Memory Stick * Processing files  *\n");
              pspDebugScreenPrintf("*******************                        *                   *\n");
              pspDebugScreenPrintf("*                                                              *\n");
              pspDebugScreenPrintf("* Processing Virtual Machine files. Please wait.               *\n");
              pspDebugScreenPrintf("*                                                              *\n");
              pspDebugScreenPrintf("****************************************************************\n");
              sceIoMkdir("ms0:/PSP/sk-gcc", 0777);
              fd = sceIoOpen(MS0_COMUNIC_FILE, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
              if (fd >= 0) {char *content = "SK-GCC: log from SK-GCC Processor"; sceIoWrite(fd, content, strlen(content)); sceIoClose(fd);};
              pspDebugScreenPrintf("* Virtual Machine #2 *   Target: flash4 * Processing Files #2  *\n");
              pspDebugScreenPrintf("**********************                  *                      *\n");
              pspDebugScreenPrintf("*                                                              *\n");
              pspDebugScreenPrintf("* File process completed. Setting up flash4 to start VM.       *\n");
              pspDebugScreenPrintf("* Do not exit the software during setup, as you may lose or co *\n");
              pspDebugScreenPrintf("* -rrupt several data.                                         *\n");
              pspDebugScreenPrintf("*                                                              *\n");
              pspDebugScreenPrintf("****************************************************************\n");
              sceIoMkdir(FLASH4_SAVE_PATH, 0777);
              fd = sceIoOpen(FLASH4_COMUNIC_FILE, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
              if (fd >= 0) {char *content2 = "SK-GCC: log from SK-GCC Processor"; sceIoWrite(fd, content2, strlen(content2)); sceIoClose(fd);};
              pspDebugScreenPrintf("\n");
              pspDebugScreenPrintf("Starting VM..\n");

}