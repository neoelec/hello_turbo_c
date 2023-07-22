#include <bios.h>
#include <ctype.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESC 27
#define MAX_FRAME 10
#define TRUE 1
#define FALSE 0
#define MAX_SPACE 3

void pulldriver(int *fra, int *number, int gd);
int pulldown(int num, int past);
int make_top(char *menu[], char *keys, int count);
void make_location(int num);
int make_menu(int num, char *menu[], char *keys, int count, int par, int pos);
void display_top(void);
void display_menu(int num);
void draw_border(int num);
int get_resp(int num);
void save_video(int num);
void restore_video(int num);
int is_in(char *s, char c);
void xorbar(int a, int b, int c, int d);

int graphic_card;

struct menu_frame {
    int startx, endx, starty, endy;
    unsigned char *p;
    char **menu;
    char *keys;
    int count;
    int active;
} frame[MAX_FRAME];

struct {
    int back;
    int front[MAX_FRAME];
    int old_position;
} location[MAX_FRAME];

int make_top(char *menu[], char *keys, int count)
{
    register int i, num;
    int x = 0, y = 1, endx, endy, len = 0;

    for (i = 0; i < count; i++) {
        len += strlen(menu[i]) + MAX_SPACE;
    }

    endy = len + 2 + y;
    endx = 1 + x;

    if ((endx + 1 > 24) || (endy + 1 > 79)) {
        printf("menu won't fit");

        return 0;
    }

    frame[0].startx = x;
    frame[0].endx = endx;
    frame[0].starty = y;
    frame[0].endy = endy;
    frame[0].menu = (char **)menu;
    frame[0].keys = keys;
    frame[0].count = count;
    frame[0].active = 0;

    for (num = 1; num <= frame[0].count; num++) {
        for (i = 0; i < frame[num].count; i++) {
            location[num].front[i] = 0;
        }

        location[num].back = 0;
        make_location(num);
    }

    return 1;
}

int make_menu(int num, char *menu[], char *keys, int count, int par, int pos)
{
    int endx, endy, i, len = 0;

    if (num > MAX_FRAME) {
        printf("Too many menus\0");

        return 0;
    }

    location[par].front[pos] = num;
    location[num].back = par;

    if (num > frame[0].count) {
        make_location(num);
    }

    for (i = 0; i < count; i++) {
        if (strlen(menu[i]) > len) {
            len = strlen(menu[i]);
        }
    }

    endy = len + 2 + frame[num].starty;
    endx = count + 2 + frame[num].startx;

    if ((endx + 1 > 24) || (endy + 1 > 79)) {
        printf("Menu won't fit");

        return 0;
    }

    frame[num].endx = endx;
    frame[num].endy = endy;
    frame[num].menu = (char **)menu;
    frame[num].keys = keys;
    frame[num].count = count;
    frame[num].active = 0;

    return 1;
}

void make_location(int num)
{
    int i, y = 0, x, boolean;

    x = frame[0].startx + 1;

    for (i = 0; i < num - 1; i++) {
        y += strlen(frame[0].menu[i]) + MAX_SPACE;
    }

    boolean = num > frame[0].count;

    frame[num].startx = boolean ? x + 1 : x;
    frame[num].starty = boolean ? frame[location[num].back].starty + 3 : y + 2;
}

void pulldriver(int *menu_frame, int *number, int gd)
{
    int temp_fra, do_again = TRUE;

    graphic_card = gd;
    *menu_frame = *number = 0;
    display_top();

    while (do_again) {
        *number = pulldown(*menu_frame, *number);

        switch (*number) {
        case -1:

            if (*menu_frame == 0) {
                do_again = FALSE;
            } else {
                restore_video(*menu_frame);
                *menu_frame = location[*menu_frame].back;
            }

            break;

        case -2:

            if (*menu_frame > 0) {
                restore_video(*menu_frame);
            }

            if (--(*menu_frame) == -1) {
                *menu_frame = location[0].old_position;
            }

            if (*menu_frame < 1) {
                *menu_frame = frame[0].count;
            }

            if (location[0].front[*menu_frame - 1] == 0) {
                location[0].old_position = *menu_frame - 1;
                *menu_frame = 0;
            } else {
                location[0].old_position = *menu_frame - 1;
            }

            break;

        case -3:

            if (*menu_frame > 0) {
                restore_video(*menu_frame);
            }

            if (++(*menu_frame) == 1) {
                *menu_frame = location[0].old_position + 2;
            }

            if (*menu_frame > frame[0].count) {
                *menu_frame = 1;
            }

            if (location[0].front[*menu_frame - 1] == 0) {
                location[0].old_position = *menu_frame - 1;
                *menu_frame = 0;
            } else {
                location[0].old_position = *menu_frame - 1;
            }

            break;

        default:
            location[*menu_frame].old_position = *number;

            if (location[*menu_frame].front[*number] != 0) {
                *menu_frame = location[*menu_frame].front[*number];
            } else {
                temp_fra = *menu_frame;

                while (temp_fra > 0) {
                    restore_video(temp_fra);
                    temp_fra = location[temp_fra].back;
                }

                do_again = FALSE;
            }

            break;
        }
    }

    restore_video(0);
}

void display_top(void)
{
    register int i;
    char **m;
    static char pat[] = { 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55 };

    m = frame[0].menu;

    if (graphic_card == HERCMONO) {
        setfillpattern(pat, 1);
        rectangle(frame[0].starty * 8, frame[0].startx * 16, frame[0].endy * 8,
                  frame[0].endx * 16);
        floodfill(frame[0].starty * 8 + 1, frame[0].startx * 16 + 1, WHITE);
    } else {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(frame[0].starty * 8, frame[0].startx * 16, frame[0].endy * 8,
            frame[0].endx * 16);
    }

    for (i = 1; i <= frame[0].count; i++) {
        outtextxy(frame[i].starty * 8, frame[0].startx * 16 + 4, m[i - 1]);
    }
}

int pulldown(int num, int past)
{
    if (!frame[num].active) {
        save_video(num);
        frame[num].active = 1;
    }

    if ((num > 0) && (past != -1)) {
        draw_border(num);
        display_menu(num);
    }

    return get_resp(num);
}

void display_menu(int num)
{
    register int i, x;
    char **m;

    x = frame[num].startx + 1;
    m = frame[num].menu;

    for (i = 0; i < frame[num].count; i++, x++) {
        outtextxy(frame[num].starty * 8, x * 16 + 4, m[i]);
    }
}

void draw_border(int num)
{
    register int x;

    x = frame[num].startx + 1;

    if (num <= frame[0].count) {
        xorbar(frame[num].starty * 8, (x - 2) * 16,
               (frame[num].starty + strlen(frame[0].menu[num - 1])) * 8,
               (x - 1) * 16);
    }

    if (graphic_card == HERCMONO) {
        setfillstyle(SOLID_FILL, BLACK);
        bar(frame[num].starty * 8, frame[num].startx * 16 + 8,
            frame[num].endy * 8, frame[num].endx * 16 - 8);
        rectangle(frame[num].starty * 8, frame[num].startx * 16 + 8,
                  frame[num].endy * 8, frame[num].endx * 16 - 8);
    } else {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(frame[num].starty * 8, frame[num].startx * 16 + 8,
            frame[num].endy * 8, frame[num].endx * 16 - 8);
    }
}

int get_resp(int num)
{
    union inkey {
        char ch[2];
        int i;
    } c;
    int arrow_choice, key_choice, x, y, ey;
    static int is_level0 = TRUE;

    arrow_choice = location[num].old_position;
    x = frame[num].startx + 1;
    y = frame[num].starty;
    ey = frame[num].endy;

    if (num > 0) {
        xorbar(y * 8, (x + arrow_choice) * 16, ey * 8,
               (x + arrow_choice + 1) * 16);

        for (;;) {
            c.i = bioskey(0);
            xorbar(y * 8, (x + arrow_choice) * 16, ey * 8,
                   (x + arrow_choice + 1) * 16);

            if (c.ch[0]) {
                key_choice = is_in(frame[num].keys, tolower(c.ch[0]));

                if (key_choice) {
                    return key_choice - 1;
                }

                switch (c.ch[0]) {
                case '\r':

                    return arrow_choice;

                case ' ':
                    arrow_choice++;
                    break;

                case ESC:

                    if (num <= frame[0].count) {
                        is_level0 = TRUE;
                    }

                    return -1;
                }
            } else {
                switch (c.ch[1]) {
                case 72:
                    arrow_choice--;
                    break;

                case 80:
                    arrow_choice++;
                    break;

                case 75:

                    if (num <= frame[0].count) {
                        return -2;
                    }

                case 77:

                    if (num <= frame[0].count) {
                        return -3;
                    }
                }
            }

            if (arrow_choice == frame[num].count) {
                arrow_choice = 0;
            }

            if (arrow_choice < 0) {
                arrow_choice = frame[num].count - 1;
            }

            xorbar(y * 8, (x + arrow_choice) * 16, ey * 8,
                   (x + arrow_choice + 1) * 16);
        }
    } else {
        xorbar(frame[arrow_choice + 1].starty * 8, (x - 1) * 16,
               (frame[arrow_choice + 1].starty +
                strlen(frame[num].menu[arrow_choice])) *
                   8,
               x * 16);

        for (;;) {
            c.i = bioskey(0);

            xorbar(frame[arrow_choice + 1].starty * 8, (x - 1) * 16,
                   (frame[arrow_choice + 1].starty +
                    strlen(frame[num].menu[arrow_choice])) *
                       8,
                   x * 16);

            if (c.ch[0]) {
                key_choice = is_in(frame[num].keys, tolower(c.ch[0]));

                if (key_choice) {
                    return key_choice - 1;
                }

                switch (c.ch[0]) {
                case '\r':
                    is_level0 = FALSE;

                    return arrow_choice;

                case ' ':
                    arrow_choice++;
                    break;

                case ESC:

                    return -1;
                }
            } else {
                switch (c.ch[1]) {
                case 75:

                    if (is_level0 == FALSE) {
                        return -2;
                    } else {
                        arrow_choice--;
                        break;
                    }

                case 77:

                    if (is_level0 == FALSE) {
                        return -3;
                    } else {
                        arrow_choice++;
                        break;
                    }

                case 80:
                    is_level0 = FALSE;

                    return arrow_choice;
                }
            }

            if (arrow_choice == frame[num].count) {
                arrow_choice = 0;
            }

            if (arrow_choice < 0) {
                arrow_choice = frame[num].count - 1;
            }

            xorbar(frame[arrow_choice + 1].starty * 8, (x - 1) * 16,
                   (frame[arrow_choice + 1].starty +
                    strlen(frame[num].menu[arrow_choice])) *
                       8,
                   x * 16);
        }
    }
}

int is_in(char *s, char c)
{
    register int i;

    for (i = 0; *s; i++) {
        if (*s++ == c) {
            return i + 1;
        }
    }

    return 0;
}

void save_video(int num)
{
    frame[num].p =
        malloc(imagesize(frame[num].starty * 8, frame[num].startx * 16,
                         frame[num].endy * 8, frame[num].endx * 16));
    getimage(frame[num].starty * 8, frame[num].startx * 16, frame[num].endy * 8,
             frame[num].endx * 16, frame[num].p);
}

void restore_video(int num)
{
    register int x;

    x = frame[num].startx + 1;

    if (num <= frame[0].count) {
        xorbar(frame[num].starty * 8, (x - 2) * 16,
               (frame[num].starty + strlen(frame[0].menu[num - 1])) * 8,
               (x - 1) * 16);
    }

    putimage(frame[num].starty * 8, frame[num].startx * 16, frame[num].p,
             COPY_PUT);

    free(frame[num].p);
    frame[num].active = 0;
}

void xorbar(int a, int b, int c, int d)
{
    int i;

    setwritemode(XOR_PUT);

    for (i = b; i < d; i++) {
        line(a, i, c, i);
    }

    setwritemode(COPY_PUT);
}
