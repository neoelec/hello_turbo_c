#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>

#define LB 0x1
#define RB 0x2

void mouse(void);
int m_button(int but);
void cursor(int x, int y);

union REGS rin, rout;
int m_x = 317, m_y = 192, m_sx = 317, m_sy = 192;

int main(void)
{
    int gd = DETECT, gm, ch = 0;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    setcolor(getmaxcolor());
    cursor(m_x, m_y);

    while (ch != 27) {
        mouse();

        while (m_button(LB)) {
            if ((m_sx != m_x) || (m_sy != m_y)) {
                cursor(m_x, m_y);
                moveto(m_sx, m_sy);
                lineto(m_x, m_y);
                cursor(m_x, m_y);
            }

            mouse();
        }

        if (m_button(RB)) {
            cursor(m_x, m_y);
            floodfill(m_x, m_y, getmaxcolor());
            cursor(m_x, m_y);
        }

        if (kbhit()) {
            ch = getch();
        }

        if (ch == 32) {
            cursor(m_x, m_y);
            cleardevice();
            cursor(m_x, m_y);
            ch = 0;
        }
    }

    closegraph();

    return 0;
}

void mouse(void)
{
    rin.x.ax = 0xb;
    int86(0x33, &rin, &rout);
    m_sx = m_x;
    m_sy = m_y;

    if (rout.x.cx || rout.x.dx) {
        cursor(m_x, m_y);
        m_x += rout.x.cx;
        m_y += rout.x.dx;

        if (m_x >= getmaxx()) {
            m_x = getmaxx();
        }

        if (m_y >= getmaxy()) {
            m_y = getmaxy();
        }

        if (m_x <= 0) {
            m_x = 0;
        }

        if (m_y <= 0) {
            m_y = 0;
        }

        cursor(m_x, m_y);
    }
}

int m_button(int but)
{
    union REGS r;

    r.x.ax = 3;
    int86(0x33, &r, &r);
    r.x.bx &= but;

    return r.x.bx;
}

void cursor(int x, int y)
{
    setwritemode(XOR_PUT);
    line(x - 14, y, x - 1, y);
    line(x + 1, y, x + 14, y);
    line(x, y - 10, x, y + 10);
    setwritemode(COPY_PUT);
}
