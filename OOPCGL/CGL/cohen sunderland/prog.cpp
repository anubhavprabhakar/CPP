

//Cohen Sutherland Line Clipping Algorithm

#include<iostream.h>
#include<conio.h>
#include<graphics.h>

const int INSIDE = 0;           //0000
const int LEFT = 1;             //0001
const int RIGHT = 2;            //0010
const int BOTTOM = 4;           //0100
const int TOP = 8;              //1000

class CohenSutherLandAlgo
{
    private:
        double x1,y1,x2,y2;         //endpoints of line
        double x_max,y_max,x_min,y_min;         //corner points of clipping window(Left Upper and Right Lower)
        
    public:
        CohenSutherLandAlgo()
        {
            x1=0.0;
            x2=0.0;
            y1=0.0;
            y2=0.0;
        }
        void getCoordinates();                          //Accept the line getCoordinates
        void getClippingRectangle();                    //Accept the clipping window
        int generateCode(double x,double y);            //Generate outcode
        void cohenSutherland();                         //Cohen Sutherland Algorithm
};

//accept line Coordinates
void CohenSutherLandAlgo::getCoordinates()
{
    cout<<"\nEnter Coordinates of P1(X1,Y1) of line segment : ";
    cout<<"\nEnter X1 Coordinate : ";
    cin>>x1;
    cout<<"\nEnter Y1 Coordinate : ";
    cin>>y1;
    cout<<"\nEnter Co-ordinate of P2(X2,Y2) of line segment : ";
    cout<<"\nEnter X2 Coordinate : ";
    cin>>x2;
    cout<<"\nEnter Y2 Coordinate : ";
    cin>>y2;
    line(x1,y1,x2,y2);
    getch();
}

//Accept Clipping window Coordinates
void CohenSutherLandAlgo::getClippingRectangle()
{
    cout<<"\nEnter the Coordinates of Clipping Window : ";
    cout<<"\nEnter the X_MIN : ";
    cin>>x_min;
    cout<<"\nEnter the Y_MIN : ";
    cin>>y_min;
    cout<<"\nEnter the X_MAX : ";
    cin>>x_max;
    cout<<"\nEnter the Y_MAX : ";
    cin>>y_max;
    rectangle(x_min,y_min,x_max,y_max);
    getch();
    
}

//Generate outcode
int CohenSutherLandAlgo::generateCode(double x,double y)
{
    int code = INSIDE;                      //code=0000 initially initializing 
    if(x<x_min)                             //lies to the left of rectangle
        code|=LEFT;
    else if(x>x_max)                        //lies to the right of rectangle
        code|=RIGHT;
    if(y<y_min)                             //lies below the rectangle
        code|=BOTTOM;
    else if(y>y_max)                        //lies above the rectangle
        code|=TOP;
    return code;
}

//Cohen SutherLand Algorithm to clip line
void CohenSutherLandAlgo::cohenSutherland()
{
    int code1=generateCode(x1,y1);                              //compute region codes for P1
    int code2=generateCode(x2,y2);                              //compute region codes for P2
    int accept=0;                                               //initialize line as outside the rectangle window
    while(1)
    {
        if((code1==0) && (code2==0))
        {
            //if both endpoints lie within rectangle
            accept=1;
            break;
        }
        else if(code1 & code2)
        {
            //if both endpoints are outside rectangle, in same region
            break;
        }
        else
        {
            //some segment of line lies within the rectangle
            int code_out;
            double x,y;
            //atleast one endpoint lies outside the rectangle
            if(code1!=0)
                code_out = code1;
            else
                code_out = code2;
            
            if(code_out & TOP)
            {
                //point is above the clip rectangle
                x=x1+(x2-x1)*(y_max-y1)/(y2-y1);
                x=x1+(x2-x1)*(y_max-y1)/(y2-y1);
                y=y_max;
            }
            else if(code_out & BOTTOM)
            {
                //point is below the rectangle
                x=x1+(x2-x1)*(y_min-y1)/(y2-y1);
                y=y_min;
            }
            else if(code_out & RIGHT)
            {
                //point is to the right of the rectangle
                y=y1+(y2-y1)*(x_max-x1)/(x2-x1);
                x=x_max;
            }
            else if(code_out & LEFT)
            {
                //point is to the left of the rectangle
                y=y1+(y2-y1)*(x_min-x1)/(x2-x1);
                x=x_min;
            }
            //intersection point x,y is found
            //Replace point outside rectangle by intersection point
            
            if(code_out ==code1)
            {
                x1=x;
                y1=y;
                code1=generateCode(x1,y1);
            }
            else
            {
                x2=x;
                y2=y;
                code2=generateCode(x2,y2);
            }
        }
    }
    if(accept==1)
    {
        cout<<"Line Accepted from "<<"("<<x1<<","<<y1<<")"<<"to"<<"("<<x2<<","<<y2<<")";
        setcolor(WHITE);
        line(x1,y1,x2,y2);
        getch();
    }
    else
    cout<<"Line Rejected"<<endl;
}
int main()
{
    CohenSutherLandAlgo c;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\tc\\bgi");
    setcolor(RED);
    c.getCoordinates();
    c.getClippingRectangle();
    //cleardevice();
    c.cohenSutherland();
    getch();
    return 0;
}
