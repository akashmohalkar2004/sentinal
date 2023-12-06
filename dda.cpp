#include<iostream>
#include<graphics.h>
using namespace std;
class pixel
{
    protected :
    int x ;
    int y ;
    public:
    pixel(int x ,int y)
    {
        x =x ;
        y = y;
    }
    virtual void draw() = 0;
};
class line : public pixel{
    int endx ,endy ;
    public:
    line( int x ,int y , int endx ,int endy):pixel( x ,y) ,endx (endx) , endy (endy) {}
     void draw()
     {
        line( x ,y , endx ,endy);
     }
};

class dda_line : public line{

    public:
    dda_line( int x ,int y ,int endx ,int endy):line(x , y , endx ,endy) {}

    void draw()
    {
        int dx = endx - x ;
        int dy = endy - y ;
        int steps = max(abs(dx),abs(dy));
        float xincreament = float (dx)/steps;
        float yincreament = float (dy)/steps ;

        float currentx = x;
        float currenty = y ;

        for(int  i =0 ; i<= steps ; i++)
        {
            putpixel(round(currentx) , round(currenty),WHITE)
            currentx += xincreament;
            currenty += yincreament;
        }
    }
};
class bresenham_line : public line{
 public:
  bresenham_line( int x ,int y ,int endx ,int endy): line( , y ,endx ,endy){}
  void draw()
  {
    int dx  = abs(endx - x );
    int dy = abs (endy - y) ;

    int sx = ( x < endx) ? 1 :-1 ;
    int sy = ( y<endy) ? 1 : -1;
    int err = dx -dy ;
    while(true)
    {
        putpixel(x,y,WHITE)
        if( x == endx && y == endy)
        {
            break; 
        }
        int e2 = 2 *err;
        if( e2 > -dy)
        {
            err -= dy;
            x += sx ;
        }
        if( e2 < dx)
        {
            err += dx;
            y += dy ;
        }
    }
  }
};

int main()
{
    int gd = DETECT , gm ;
    initgraph( &gd ,& gm , NULL);
    dda_line s(50 ,50 ,200,50);
    bresenham_line do(50 ,50 ,200 ,100);
    dda_line d( 50,150,200,50);
    bresenham_line dash( 50 ,200 ,200 ,200);
    dda_line t(50 ,250,200,250);
    s.draw();
    do.draw();
    d.draw();
    dash.draw();
    t.draw();

    delay(5000);
    closegraph();

    return 0 ;

}