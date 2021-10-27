#include<iostream>
using namespace std;

class complex
{
private:
    float real,imag;
public:
    complex();
    complex operator+(complex);
    complex operator*(complex);
    complex operator/(complex);
    friend complex operator -(complex x,complex y);
    friend istream & operator>>(istream &, complex &);
    friend ostream & operator<<(ostream &, complex &);
};
complex::complex()
{
    real=0,imag=0;
}
complex operator-(complex x, complex y)
{
    complex temp;
    temp.real=x.real-y.real;
    temp.imag=x.imag-y.imag;
    return temp;
}

istream & operator>>(istream & din, complex &c)
{
    cout<<"\nEnter real part: ";
    din>>c.real;
    cout<<"Enter imaginary part: ";
    din>>c.imag;
    return din;
}

ostream & operator<<(ostream & dout, complex &c)
{
    dout<<c.real<<" +i"<<c.imag;
    return dout;
}

complex complex::operator+(complex c)
{
    complex temp;
    temp.real=real+c.real;
    temp.imag=imag+c.imag;
    return temp;
}

complex complex::operator*(complex c)
{
    complex mul;
    mul.real=real*c.real-imag*c.imag;
    mul.imag=real*c.imag+imag*c.real;
    return mul;
}

complex complex::operator/(complex c)
{
    complex temp;
    int den=(c.real*c.real+c.imag*c.imag);
    temp.real=(real*c.real+imag*c.imag)/den;
    temp.imag=(imag*c.real-real*c.imag)/den;
    return temp;
}

int main()
{
    complex c1,c2,c3;
    int p=1,ch;
    do
    {
    cout<<"\n===============MENU================\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division";

    cout<<"\nEnter 1st complex number: ";
    cin>>c1;;
    cout<<"\nEnter 2nd complex number: ";
    cin>>c2;
    cout<<"\nFirst complex number is: ";
    cout<<c1;
    cout<<"\nSecond complex number is: ";
    cout<<c2;

    cout<<"\nEnter your choice of operation(1-4): ";
    cin>>ch;

    if(ch==1)
    {
       c3=c1+c2;
       cout<<"\nAddition is: "<<c3;
    }
    else if(ch==2)
    {
       c3=c1-c2;
       cout<<"\nSubtraction is: "<<c3;
    }
    else if(ch==3)
    {
        c3=c1*c2;
        cout<<"\nMultiplication is: "<<c3;
    } 
    else if(ch==4)
    {
        c3=c1/c2;
        cout<<"\nDivision is: "<<c3;
    }
    else{
        cout<<"\nINVALID CHOICE";
    }
    cout<<"\n\nDo you want to run again?\n(1 for yes/0 for no)";
    cin>>p;
    }while(p==1);
    cout<<"\nThank you";
    return 0;
}