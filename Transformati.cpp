#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

struct point
{
    float x,y;
};

void translate(point *arr, int n = 3)
{
    float tx = 20;
    float ty = 20;
    for(int i = 0; i<3; i++)
    {
        arr[i].x += tx;
        arr[i].y += ty;
    }
}

void rotate(point *arr, float ang = 50, int n = 3)
{
    ang = ang * M_PI/180;
    for(int i = 0; i<n ;i++)
    {
        float x = arr[i].x * cos(ang) + arr[i].y*sin(ang);
        float y = (-1)*arr[i].x * sin(ang) + arr[i].y*cos(ang);
        arr[i].x = x;
        arr[i].y = y;
    }
}

void Scale(point *arr, int n)
{
    float sx = 2;
    float sy = 2;
    for(int i = 0; i<3; i++)
    {
        arr[i].x *= sx;
        arr[i].y *= sy;
    }
}

void Display(point *arr, int n)
{
    for(int i = 0; i<n ;i++)
    {
        line(arr[i].x, arr[i].y, arr[(i+1)%n].x, arr[(i+1)%n].y);
    }

}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    point arr[] = {{65,230},{235,231},{150,80}};
    Display(arr, 3);
    getch();

    cleardevice();
    
    translate(arr);
    Display(arr,3);
    getch();
    closegraph();
}