#include <stdio.h>

#include "module1.h"
#include "module2.h"
#include "module3.h"

char *m1 = "Print char *m1, MODULE1.C's Global Variable.\n";

int main(void)
{
    printf("\nNow in MODULE1.C's main()\n");
    call_module2();
    call_module3();
    printf("\t%s", m3);
    printf("End of main()\n");

    return 0;
}
