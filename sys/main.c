#include "../sk-gcc/lib/sk.h"
#include <pspkernel.h>
#include <pspsdk.h>
#include <pspdebug.h>
#include <pspctrl.h>

PSP_MODULE_INFO("sk-gcc-sys", 0, 1, 1);

int worker(int argc, char *argv)
{
              pspDebugScreenInit();
              // Making a Loading animation with just a -, a \, a |, and a /.
              write();
              while(1)
              {
                            acornCls();
                            acorn("-  Loading.", NULL);
                            sceKernelDelayThread(100000);

                            acornCls();
                            acorn("\\  Loading..", NULL);
                            sceKernelDelayThread(100000);

                            acornCls();
                            acorn("|  Loading...", NULL);
                            sceKernelDelayThread(100000);

                            acornCls();
                            acorn("/  Loading....", NULL);
                            sceKernelDelayThread(100000);

                            acornCls();
              };
              return 0;
};
int module_start(int argc, char *argv)
{
              SceUID thid = sceKernelCreateThread("wokeloader", worker, 0x18, 0xFA0, 0, NULL);

              if (thid >= 0)
              {
                            sceKernelStartThread(thid, argc, argv);
              }
              return 0;
}
int modulestop(int argc, char *argv)
{
              return 0;
}