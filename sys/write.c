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
              fcopen(checkout, "host0:/", "test.", "A3", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777, "Aoo!");
              fcopen(checkout2, "host0:/", "int.", "A3", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777,
              "+--------------------+\n"
              "| Init: host0:/      |\n"
              "+--------------------+\n"
);
}
