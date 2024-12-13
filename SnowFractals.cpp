#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

void Snowfractal(int x1, int y1, int x2, int y2, int n)
{
    float ang = 60*M_PI/180;
    float x3 = (2*x1+x2)/3;
    float y3 = (2*y1+y2)/3;
    float x4 = (x1+x2*2)/3;
    float y4 = (y1+2*y2)/3;

    float x = x3 + (x4-x3)*cos(ang) + (y4-y3)*sin(ang);
    float y = y3 - (x4-x3)*sin(ang) + (y4-y3)*cos(ang);

    if(n == 0)
    {
        line(x1,y1,x2,y2);
    }
    else
    {
        Snowfractal(x1,y1,x3,y3,n-1);
        Snowfractal(x3,y3,x,y,n-1);
        Snowfractal(x,y,x4,y4,n-1);
        Snowfractal(x4,y4,x2,y2,n-1);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 65, y1 = 230, x2 = 235, y2 = 230, x3 = 150, y3 = 80, n = 3;
    Snowfractal(x1,y1,x2,y2,n);
    Snowfractal(x2,y2,x3,y3,n);
    Snowfractal(x3,y3,x1,y1,n);


    getch();
    closegraph();
    return 0;
}