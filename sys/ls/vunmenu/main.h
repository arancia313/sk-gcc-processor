#pragma once
#ifndef vunmenu

#include "../../../sk-gcc/lib/sk.h"
#include <pspkernel.h>
#include <stdio.h>
#include <string.h>
#include <pspdebug.h>

#define vunmenu

void ErrorExit(const char *thing, const char **string, const char ***number)
{
              acorn(thing, string);
              sceKernelDelayThread(number);
              sceKernelExitGame();
}
#endif