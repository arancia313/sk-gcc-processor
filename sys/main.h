#include <pspkernel.h>
#include <pspsdk.h>
#include <pspdebug.h>
#include <sk.h>

static inline void clearfilesh(void)
{
              pspDebugScreenInit();
              acorn("Removing files from host0:/...", NULL);
              sceIoClose("host0:/");
              sceIoRemove("host0:/int.A3");
              sceIoRemove("host0:/test.A3");
              sceIoRemove("host0:/sys/list/cv.A3");
              acorn("Removal is complete.", NULL);
}