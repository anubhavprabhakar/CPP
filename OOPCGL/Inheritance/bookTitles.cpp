#include<iostream>
using namespace std;

class publication
{
private:
    string title;
    float price;

public:
    publication()
    {
        title = "NULL";
        price = 0.0;
    }

    publication(string title, float price)
    {
        this->title = title;
        this->price = price;
    }

    void getData();
    void putData();
};

void publication::getData()
{
    cout << "\nEnter title: ";
    cin >> title;
    cout << "\nEnter price: ";
    cin >> price;
}

void publication::putData()
{
    try
    {
        if (title.length() < 3)
            throw title;
    }
    catch (string)
    {
        cout << "\nException raised: Title below 3 characters is not allowed";
        title = "NULL";
    }
    try
    {
        if (price <= 0.0)
            throw price;
    }
    catch (float p)
    {
        cout << "\nException raised: Price not valid:  "<<p;
        price = 0.0;
    }
    cout << "\nTitle is: " << title;
    cout << "\nPrice is: " << price;
}

class Book : public publication
{
private:
    int pages;

public:
    Book() : publication()
    {
        pages = 0;
    }

    Book(string title, float price, int pages) : publication(title, price)
    {
        this->pages = pages;
    }

    void getData()
    {
        publication::getData();
        cout << "\nEnter no. of pages in book: ";
        cin >> pages;
    }

    void putData()
    {
        publication::putData();
        try
        {
            if (pages <= 0)
                throw pages;
        }
        catch (int i)
        {
            cout << "\nException raised: Pages not valid:  "<<i;
            pages = 0;
        }
        cout << "\nPages are: " << pages;
    }
};

class Cassette : public publication
{
private:
    float playtime;

public:
    Cassette() : publication()
    {
        playtime = 0.0;
    }
    Cassette(string title, float price, float playtime) : publication(title, price)
    {
        this->playtime = playtime;
    }

    void getData()
    {
        publication::getData();
        cout << "\nEnter play time of cassette: ";
        cin >> playtime;
    }

    void putData()
    {
        publication::putData();
        try
        {
            if (playtime < 0.0)
                throw playtime;
        }
        catch (float f)
        {
            cout << "\nException raised: Playtime not valid:  " << f;
            playtime = 0.0;
        }
        cout << "\nPlaytime is: " << playtime;
    }
};

int main(){
    Book book;
    cout<<"\n================   Book   =================\n";
    book.getData();
    cout<<"\n================ Cassette =================\n";
    Cassette cassette;
    cassette.getData();
    cout<<"\n================   Book   =================\n";
    book.putData();
    cout<<"\n================ Cassette =================\n";
    cassette.putData();

    return 0;
}