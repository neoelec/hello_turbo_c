#include <stdio.h>

#include "module1.h"

char *m2 = "Print char *m2, MODULE2.C's Global Variable.\n";

void call_module2()
{
    printf("\tNow call_module2() in MODULE2.C\n");
    printf("\t\t%s", m1);
    printf("\tEnd of call_moduel2()\n\n");
}
