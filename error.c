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

void errorms(void)
{
              acornCls();
              acorn("\n", NULL);
              acorn(" Could not operate VM. The VM has been stopped.\n", NULL);
              acorn(" This could be because the Memory stick could have been removed\n", NULL);
              acorn(" or a critical file is missing.\n", NULL);
              acorn("\n", NULL);
              acorn(" Aborting.", NULL);
              sceKernelDelayThread(5000000);
              main();
};

void errorhost(void)
{
              acornCls();
              acorn("\n", NULL);
              acorn(" Could not resolve host0:/.\n", NULL);
              acorn(" PSPLINK setup could either be absent or host0:/ wasn't reachable.\n", NULL);
              acorn("\n", NULL);
              acorn(" Aborting.\n", NULL);
              sceKernelDelayThread(5000000);
              main();
}