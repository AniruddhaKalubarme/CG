#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

int xl = 100, yl = 100, xh = 300, yh = 300;

void code(int *arr, int x, int y)
{
    arr[0] = y>yh;
    arr[1] = y<yl;
    arr[2] = x>xh;
    arr[3] = x<xl;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int a[4], b[4];
    int x1 = 10, y1 = 200, x2 = 250, y2 = 150;
    code(a,x1,y1);
    code(b,x2,y2);
    float m = (y2-y1)/(x2-x1);
    rectangle(xl,yl,xh,yh);
    if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0)
    {
        line(x1, y1, x2, y2);
    }
    else if(a[0] && b[0] || a[1] && b[1] || a[2] && b[2] || a[3] == b[3])
    {
        cout<<"LINE CLIPPED";
    }
    else if(a[0] == 1 && b[0] == 0)
    {
        float xnew = x1+(yh-y1)/m;
        line(xnew, yh, x2, y2);
    }
    else if(a[1] == 1 && b[1] == 0)
    {
        float xnew = x1+(yl-y1)/m;
        line(xnew, yl, x2, y2);
    }
    else if(a[2] == 1 && b[2] == 0)
    {
        float ynew = y1+(xh-x1)*m;
        line(xh, ynew, x2, y2);
    }
    else if(a[3] == 1 && b[3] == 0)
    {
        float ynew = y1+(xl-x1)*m;
        line(xl, ynew, x2, y2);
    }

    getch();
    closegraph();
    return 0;
}


