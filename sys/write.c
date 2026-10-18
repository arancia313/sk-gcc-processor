#include <pspsdk.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <string.h>
#include <stdio.h>

// Really important.
#include "../sk-gcc/lib/sk.h"

void write(void)
{
              int checkout;
              int checkout2;
              int checkout3;
              fcopen(checkout, "host0:/", "test.", "A3", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777, "Aoo!");
              fcopen(checkout2, "host0:/", "int.", "A3", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777,
              "+--------------------+\n"
              "| Init: host0:/      |\n"
              "+--------------------+\n"
);
              sceIoMkdir("host0:/sys/list", 0777);
              fcopen(checkout3, "host0:/sys/list/", "cv.", "A3", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777,
              "0x2987\n"
              "0x4832\n"
              "0x4820\n"
              "0x1209\n"
);
}
