#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

void DDA(float x1, float y1, float x2, float y2)
{
    float dx = abs(x2-x1);
    float dy = abs(y2-y1);

    float step;
    if(dx>=dy)
    step = dx;
    else
    step = dy;

    dx = (x2-x1)/step;
    dy = (y2-y1)/step;

    int i = 0;
    
    while(i<=step)
    {
        putpixel(x1,y1,RED);
        x1+=dx;
        y1+=dy;
        i++;
        delay(10);
    }
}

void BoundaryFill(int x, int y, int newc, int boundry)
{
    if(getpixel(x,y) != newc && getpixel(x,y) != boundry && getpixel(x+1,y) != boundry && getpixel(x-1,y) != boundry && getpixel(x,y+1) != boundry && getpixel(x,y-1) != boundry)
    {
        putpixel(x,y,newc);
        BoundaryFill(x+1, y, newc, boundry);
        BoundaryFill(x-1, y, newc, boundry);
        BoundaryFill(x, y+1, newc, boundry);
        BoundaryFill(x, y-1, newc, boundry);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    setcolor(1);
    DDA(65,230,235,230);
    DDA(235,230,150,80);
    DDA(150,80,65,230);

    BoundaryFill(150,150,5,RED);

    getch();
    closegraph();
    return 0;
}