//implementation of function template
//that is function can take any data type as parameter

#include<iostream>
using namespace std;

template <class T>
void sort() //sort<int>, sort<double>, sort<float>
{
    int i, j, num;
    T temp;
    T n[25];
    cout<<"\nHow many numbers you want to enter: ";
    cin>>num;
    cout<<"\nEnter "<<num<<" numbers: ";
    for(i=0; i<num; i++){
        cin>>n[i];
    }

    //selection sort
    for(i=0; i<num-1; i++){
        for(j=i+1; j<num; j++){
            if(n[i]>n[j]){
                temp=n[i];
                n[i]=n[j];
                n[j]=temp;
            }
        }
    }

    cout<<"\nSorted array: ";
    for(i=0; i<num; i++){
        cout<<n[i]<<"  ";
    }
}



int main(){
    int choice;
    char ans;
    do{
        cout<<"\nSelection sort using func temp";
        cout<<"\n1 Integer sort.";
        cout<<"\n2 Float sort."<<endl;
        cin>>choice;

        switch(choice){
            case 1: sort<int>();
                    break;
            case 2: sort<float>();
                    break;
            default: cout<<"\nPlease enter valid choice.";
                    break;
        }
        cout<<"\nDo you wish to continue?(Y/N)";
        cin>>ans;
    }while(ans=='Y' || ans=='y');
    return 0;
}