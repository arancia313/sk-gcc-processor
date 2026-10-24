#pragma once
#ifndef vunmenu

#include <sk.h>
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
#endif