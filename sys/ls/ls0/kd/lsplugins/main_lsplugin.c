#include <pspsdk.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <pspdebug.h>
#include <sk.h>

PSP_MODULE_INFO("ls0_kd", 0, 1, 1);

int module_start(int argc, char *argv)
{
              pspDebugScreenInit();
              acorn("\n", NULL);
              acorn(" This is a sample.\n", NULL);
              SceCtrlData pad;
              while(1)
              {
                            sceCtrlReadBufferPositive(&pad, 1);
                            if (pad.Buttons & PSP_CTRL_CROSS)
                            {
                                          acorn(" Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!Aoo!\n", NULL);
                            };
                            if (pad.Buttons & PSP_CTRL_TRIANGLE)
                            {
                                          return 0;
                            };
              };
}