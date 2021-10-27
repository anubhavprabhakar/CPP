#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class myfile
{
    char str[100];

public:
    void createOutputFile()
    {
        fstream a_file("example.txt", ios::in | ios::out | ios::trunc);

        a_file << "This text will now be inside of example.txt";
        a_file.close();

        ifstream b_file("example.txt");

        while(b_file >> str){
            cout << str << " ";
        }

        cin.get();
        b_file.close();
        
        
    }
};

int main()
{
    myfile mf;
    mf.createOutputFile();
    return 0;
}
