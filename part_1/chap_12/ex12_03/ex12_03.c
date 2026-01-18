#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define DEG_TO_RAD (M_PI / 180)

typedef struct polar_v {
    double magnitude;
    double angle;
} POLAR_V;

typedef struct rect_v {
    double x;
    double y;
} RECT_V;

RECT_V polar_to_rect(POLAR_V);

int main(void)
{
    POLAR_V input;
    RECT_V result;

    puts("Enter the magnitude and angle( degrees ); enter q to quit:");

    while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2) {
        result = polar_to_rect(input);
        printf("x = %0.2lf, y = %0.2lf\n", result.x, result.y);
    }

    return 0;
}

RECT_V polar_to_rect(POLAR_V pv)
{
    RECT_V rv;

    rv.x = pv.magnitude * cos(pv.angle * DEG_TO_RAD);
    rv.y = pv.magnitude * sin(pv.angle * DEG_TO_RAD);

    return rv;
}
