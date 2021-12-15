#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
class kochcurve
{
    private:
    int x1,y1,x2,y2,IT;  //it=iteration
    
    public:
    void koch(int x1,int y1,int x2,int y2,int IT);
};

void kochcurve::koch(int x1,int y1,int x2,int y2,int IT)
{
    float angle=60*M_PI/180;
    int x3=(2*x1+x2)/3;
    int y3=(2*y1+y2)/3;
    int x4=(x1+2*x2)/3;
    int y4=(y1+2*y2)/3;
    int x=x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
    int y=y3-(x4-x3)*sin(angle)+(y4-y3)*cos(angle);
    
    if(IT>0)
    {   
        koch(x1,y1,x3,y3,IT-1);
        koch(x3,y3,x,y,IT-1);
        koch(x,y,x4,y4,IT-1);
        koch(x4,y4,x2,y2,IT-1);
        
    }
    else
    {
        line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
    }
    
}
int main(void)
{   
    kochcurve k1;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\tc\\bgi");
    int x1=100,y1=200,x2=400,y2=200;
    line(x1,y1,x2,y2);
    delay(900);
    cleardevice();   
    
    for(int i=0;i<=5;i++)
    {
        setcolor(i+1);
        k1.koch(x1,y1,x2,y2,i);   //for koch curve
        /*k1.koch(200,266,100,100,i);   //these 3 lines for snowflake
        k1.koch(100,100,300,100,i);
        k1.koch(300,100,200,266,i);*/
        getch();
        cleardevice();
        
    }
    return 0;
    
}
