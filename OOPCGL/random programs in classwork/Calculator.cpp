#include<iostream>
using namespace std;
class Calc
{
    private:
        int num1, num2, res, r; //data members
    public:
        Calc() //default constructor - initialising data members
        {//is called whenever calc obj is made
            num1=0;
            num2=0;
            res=0;
        }
        int getnos(int,int); //member function - for dynamically accepting number from user
        int add();           //member function - for addition
        int sub();           //member function - for substraction
        int mul();           //member function - for multiplication
        int dandr();         //member function - for division
};


int Calc::getnos(int a, int b)
{
    num1=a;
    num2=b;
    return 0;
}

int Calc::add()
{
    res=num1+num2;
    cout<<num1<<" + "<<num2<<" = "<<res;
    return 0;
}

int Calc::sub()
{
    res=num1-num2;
    cout<<num1<<" - "<<num2<<" = "<<res;
    return 0;
}

int Calc::mul()
{
    res=num1*num2;
    cout<<num1<<" x "<<num2<<" = "<<res;
    return 0;
}

int Calc::dandr()
{
    res=num1/num2;
    r=num1%num2;
    cout<<"Quotient = "<<res<<" ; Remainder = "<<r;
    return 0;
}

int main()
{
    Calc obj; //creating object
    char ch;
    int p=0;
    int n1, n2;
    do
    {
        cout<<"**************CALCULATOR*******************"<<endl;
        cout<<"Enter first number, operator, second number"<<endl;
        cin>>n1>>ch>>n2;
        obj.getnos(n1,n2);
        switch(ch)
        {
            case '+':
                obj.add();
                break;
            case '-':
                obj.sub();
                break;
            case '*':
                obj.mul();
                break;
            case '/':
                obj.dandr();
                break;
            default:
                cout<<"Wrong choice";
        }
        cout<<endl<<"Enter 0 to continue, any other number to stop"<<endl;
        cin>>p;
    }while(p==0);
    cout<<"Thank You, the program has ended";
}

//https://www.onlinegdb.com/blog/brief-guide-on-how-to-use-onlinegdb-debugger/