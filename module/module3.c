#include <stdio.h>

#include "module2.h"

char *m3 = "Print char *m3, MODULE3.C's Global Variable.\n";

void call_module3(void)
{
    printf("\tNow call_module3() in MODULE3.C\n");
    printf("\t\t%s", m2);
    printf("\tEnd of call_moduel3()\n\n");
}
