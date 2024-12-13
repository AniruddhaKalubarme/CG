#include<iostream>
#include<graphics.h>
using namespace std;

void sky(int color)
{
    setfillstyle(SOLID_FILL, color);
    bar(0,0,getmaxx(), getmaxy()-150);
}

void sun(int x, int y, int rad)
{
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x,y,rad, rad);
}

void ground()
{
    setfillstyle(SOLID_FILL ,GREEN);
    bar(0, getmaxy()-150, getmaxx(), getmaxy());
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int Height = getmaxy();
    int Width = getmaxx();
    int rad = 50;

    for(int i = Height; i>Height-400; i--)
    {
        delay(5);
        sky(LIGHTBLUE);
        sun(getmaxx()/2, i, rad);
        ground();
    }

    for(int i = Height-400; i<Height; i++)
    {
        delay(5);
        sky(DARKGRAY);
        sun(getmaxx()/2, i, rad);
        ground();
    }

    getch();
    closegraph();
    return 0;
}