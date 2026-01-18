#include <conio.h>
#include <stdio.h>

int main(void)
{
    struct text_info r;

    gettextinfo(&r);
    printf(
        "WINDOW  Left : %3hhu  Right :  %3hhu  Top : %3hhu  Bottom : %3hhu\n",
        r.winleft, r.winright, r.wintop, r.winbottom);
    printf("Attribute :  %3hhu     Normattr : %3hhu\n", r.attribute,
           r.normattr);
    printf("Mode : %3hhu      X : %3hhu      Y : %3hhu\n", r.currmode, r.curx,
           r.cury);
    printf("SCREEN   Height : %3hhu       Width : %3hhu\n", r.screenheight,
           r.screenwidth);

    return 0;
}
