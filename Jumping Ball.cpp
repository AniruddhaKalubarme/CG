#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    while(true)
    {
        for(int i = 50; i<getmaxy() - 50; i++)
        {
            cleardevice();
            setbkcolor(GREEN);
            setfillstyle(SOLID_FILL, RED);
            fillellipse(getmaxx()/2, i, 50, 50);
            delay(10);
        }

        for(int i = getmaxy() - 50; i > 50; i--)
        {
            cleardevice();
            setbkcolor(GREEN);
            setfillstyle(SOLID_FILL, RED);
            fillellipse(getmaxx()/2, i, 50, 50);
            delay(10);
        }
    }
    getch();
    closegraph();
    return 0;
}