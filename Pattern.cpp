#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

void DDA(float x1, float y1, float x2, float y2)
{
    float dx = abs(x2-x1);
    float dy = abs(y2-y1);

    float step;
    if(dx>dy)
    {
        step = dx;
    }
    else    
        step = dy;

    dx = (x2-x1) / step;
    dy = (y2-y1) / step;

    float x = x1;
    float y = y1;

    int i = 1;
    while(i<=step)
    {
        putpixel(round(x), round(y), RED);
        x += dx;
        y += dy;
        i++;
        delay(10);
    }
}

void DrawCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2*r;

    while(x<=y)
    {
        putpixel(xc+x, yc+y, RED);
        putpixel(xc+x, yc-y, RED);
        putpixel(xc-x, yc+y, RED);
        putpixel(xc-x, yc-y, RED);
        putpixel(xc+y, yc+x, RED);
        putpixel(xc+y, yc-x, RED);
        putpixel(xc-y, yc+x, RED);
        putpixel(xc-y, yc-x, RED);
        delay(10);

        if(d>=0)
        {
            d = d + 4*(x-y)+10;
            y--;
        }
        else
            d += 4*x + 6;
        x++;
    }
}

int main()
{
    int gd = DETECT , gm;
    initgraph(&gd, &gm, NULL);

    DDA(65,230,235,231);
    DDA(150,80,235,231);
    DDA(150,80,65,230);

    DrawCircle(150, 180, 100);
    DrawCircle(150, 180, 50);

    getch();
    closegraph();
    return 0;
}