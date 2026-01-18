#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int gd = EGA;
    int gm = EGAHI;
    int i, j, size, midy;
    void *buf;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    setvisualpage(0);

    size = imagesize(0, 0, getmaxx(), 1);
    buf = malloc(size);
    randomize();
    midy = getmaxy() / 2;

    while (!kbhit()) {
        setactivepage(1);

        for (i = 0; i < 100; i++) {
            setcolor(random(getmaxcolor()) + 1);
            circle(random(getmaxx()), random(getmaxy()), random(100));
            line(random(getmaxx()), random(getmaxy()), random(getmaxx()),
                 random(getmaxy()));
        }

        for (i = midy, j = midy; i > 0; i -= 2, j += 2) {
            setactivepage(1);
            getimage(0, i, getmaxx(), i + 1, buf);
            setactivepage(0);
            putimage(0, i, buf, COPY_PUT);

            setactivepage(1);
            getimage(0, j, getmaxx(), j + 1, buf);
            setactivepage(0);
            putimage(0, j, buf, COPY_PUT);
        }

        setactivepage(1);
        cleardevice();
    }

    closegraph();

    return 0;
}
