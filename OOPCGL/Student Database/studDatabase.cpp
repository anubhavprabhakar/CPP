#include<iostream>
#include<string.h>
using namespace std;
#define max 100;
class per_info
{
	    string lic,dob,bldgrp;
	     public:
	       per_info();
	       per_info(per_info &);
	       ~per_info()
	       {
		      cout<<"\nDESTRUCTOR IS CALLED!!!!!"<<endl<<"RECORD DELETED SUCCESSFULLY"<<endl;
	       }
	       friend class student;
};

per_info::per_info()
{
	    lic="ABD4567";
	    dob="02/03/1994";
	    bldgrp="A-";
}

per_info::per_info(per_info &obj)
{
	    lic=obj.lic;
	    dob=obj.dob;
	    bldgrp=obj.bldgrp;
}

class student 
{
	string name,address,year;
        char div;
	int roll_no;
	long long mob;
	static int cnt;
	public:
	void create(per_info &);
	void display(per_info &);
        inline static void inccnt() {
		cnt++;
		
	}
			    
	inline static void showcnt() {
		cout<<"\nTOTAL NO OF RECORDS ARE : "<<cnt;
		
	}
	
        student();
	student(student &);
	~student() {
		cout<<"\nDESTRUCTOR IS CALLED!!!"<<endl<<"RECORD DELETED SUCCESSFULLY"<<endl;
	}
};

int student::cnt;

student::student() {
	    name="Anubhav";
	    address="Munger";
	    year="2024";
	    div='A';
	    roll_no=52;
	    mob=9315227627;
}

student::student(student &obj) {
	this->name=obj.name;
	this->address=obj.address;
	this->year=obj.year;
	this->div=obj.div;
	this->roll_no=obj.roll_no;
	this->mob=obj.mob;
}

void student::create(per_info &obj) {
	cout<<"\nNAME : "<<endl;
	cin>>name;
	cout<<"\nADDRESS : "<<endl;
	cin>>address;
	cout<<"\nDATE OF BIRTH : "<<endl;
	cin>>obj.dob;
	cout<<"\nYEAR OF GRADUATION : "<<endl;
	cin>>year;
	cout<<"\nDIVISION : "<<endl;
	cin>>div;
	cout<<"\nROLL NUMBER : "<<endl;
	cin>>roll_no;
	cout<<"\nBLOOD GROUP : "<<endl;
	cin>>obj.bldgrp;
	cout<<"\nLICENSE NUMBER : "<<endl;
	cin>>obj.lic;
	cout<<"\nPHONE NUMBER : "<<endl;
	cin>>mob;
}

void student::display(per_info &obj) {
	
	cout<<name<<"\t\t"<<address<<"\t\t"<<obj.dob<<"\t"<<year<<"\t\t"<<div<<"\t\t"<<roll_no<<"\t\t"<<obj.bldgrp<<"\t\t"<<obj.lic<<"\t\t"<<mob<<endl;

	cout<<"\n============================================================================================================================================="<<endl;
}

int main() {
	int n; 
      	int ch;
	char ans;
	    
	
	cout<<"\nENTER NO OF STUDENTS : "<<endl;
	cin>>n;
	cout<<"\n*********"<<endl;
	student *sobj=new student[n];
	per_info *pobj=new per_info[n];
		 
	do {

		cout<<"\n MENU \n 1.Create Database \n 2.Display Database \n 3. Copy Constructor\n 4. Default Constructor\n 5.Delete (Destructor) "<<endl;
		cout<<"\n Enter Your Choice: "<<endl;
		cin>>ch;

		switch(ch) {
			case 1:
				{

					for(int i=0;i<n;i++) {
							sobj[i].create(pobj[i]);
							sobj[i].inccnt();
					}
				} 
				break;

			case 2:
				{
					sobj[0].showcnt();
					cout<<"\n============================================================DETAILS FROM DATABASE============================================================"<<endl;
					cout<<"Name\t\tAddress\t\tDOB\t\tYear\t\tDivision\tRoll No.\tBlood Group\tLic. No.\tPhn No."<<endl;
					cout<<"\n============================================================================================================================================="<<endl;
					
					for(int i=0;i<n;i++) {
						sobj[i].display(pobj[i]);
					}
				}
				break;

			case 3:
				{
					student obj1;
					per_info obj2;
					obj1.create(obj2);
					student obj3(obj1);
					per_info obj4(obj2);

					cout<<"\nCopy Constructor is called \n";
					obj3.display(obj4);
				}
				break;

			case 4:
				{
					student obj1;
					per_info obj2;
					cout<<"\n============================================================DETAILS FROM DATABASE============================================================"<<endl;
					cout<<"Name\t\tAddress\t\tDOB\t\tYear\t\tDivision\tRoll No.\tBlood Group\tLic. No.\tPhn No."<<endl;
					cout<<"\n============================================================================================================================================="<<endl;
					obj1.display(obj2);
				}
				break;

			case 5:
				delete [] sobj;
				delete [] pobj;
		}

		cout<<"\n Want to continue:(y/n)";

		cin>>ans;
	}while(ans=='y');
		  
	return 0;
}
