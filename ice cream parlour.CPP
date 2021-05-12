#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

class ice
{
protected:

    char name[20];
    int code;
    int rate;
    int qty;

public:

    void write();
	void view();
	void getdata();
	void read();

}o1;

class record:public ice
{
public:
    void add();
    void sale1();
	void delete_record();
	void add1();
	void menu();
	record() //constructor
	{
        cout<<"\t\t";
        cout.width(25);
        cout.fill('*');
        cout<<"Welcome";
        cout.width(19);
        cout.fill('*');
        cout<<"*";

	}
	~record() //Destructor
	{
	    cout<<"\n";
        cout.width(31);
        cout.fill('#');
        cout<<"__!!! Thank you !!!__";
        cout.width(13);
        cout.fill('#');
        cout<<"#";
	    getch();
	}

}r1;


void record::menu()
{
    int ch;
    do
    {
        cout<<"\n\n\n\t\t\t|-------------------------|";
        cout<<"\n\t\t\t|         Main Menu       |";
        cout<<"\n\t\t\t|-------------------------|";
        cout<<"\n\n\t\t-------------------------------------------";
        cout<<"\n\t\t             1. Add stock                  ";
        cout<<"\n\t\t-------------------------------------------";
        cout<<"\n\t\t             2. Delete item                ";
        cout<<"\n\t\t-------------------------------------------";
        cout<<"\n\t\t             3. Sale item                  ";
        cout<<"\n\t\t-------------------------------------------";
        cout<<"\n\t\t             4. View Items                 ";
        cout<<"\n\t\t-------------------------------------------";
        cout<<"\n\t\t             5. Exit                       ";
        cout<<"\n\t\t-------------------------------------------";
        cout<<"\n\n\t\t\t Enter your choice:";
        cin>>ch;

        switch(ch)
        {
        case 1: r1.add();
        break;

        case 2: r1.delete_record();
        break;

        case 3: r1.sale1();
        break;

        case 4: r1.read();
        break;

        case 5: exit(0);
        break;

        default: cout<<"\n\t\tInvalid Choice; Press any key to continue :- ";
        break;
        }
        getch();
    }while(ch!=5);
}


void record::add()
{

    int ch1;

    cout<<"\n\n\t\t|-------------------------------------------|";
    cout<<"\n\t\t|           1.Add new item                  |";
    cout<<"\n\t\t|-------------------------------------------|";
    cout<<"\n\t\t|           2.Add Existing item Quantity    |";
    cout<<"\n\t\t|-------------------------------------------|";
    cout<<"\n\t\t|           3.Exit                          |";
    cout<<"\n\t\t|-------------------------------------------|";
    cout<<"\n\n\t\t\tEnter your choice:";
    cin>>ch1;
    cout<<"\n\t\t\t-------------------\n";
	switch(ch1)
    {
    case 1: write();
    break;

    case 2: add1();
    break;

    case 3: exit(0);
    break;
    }
}


void record :: add1()
{

    fstream fp;
    int pos;
    int n;
    int q;

    read();

    fp.seekg(0);
    fp.open("ice2.txt",ios::binary|ios::in|ios::out);
    cout<<"\n\n\n\t\tEnter code of ice cream flavour:";
    cin>>n;

    while(fp.read((char*)&o1,sizeof(o1)))
    {
        if(n==code)
        {
            cout<<"\n\t\tEnter quantity:";
            cin>>q;
            pos= -1 * sizeof(o1);
            fp.seekp(pos,ios::cur);
            qty=qty+q;
            fp.write((char*)&o1,sizeof(o1));
            fp.close();
            break;
        }
    }
    read();
}


void record :: sale1()
{

    fstream fp;
    int pos;
    int n;
    int q;

    read();

    fp.seekg(0);
    fp.open("ice2.txt",ios::binary|ios::in|ios::out);
    cout<<"\n\n\n\t\tEnter code of ice cream flavour:";
    cin>>n;
    while(fp.read((char*)&o1,sizeof(o1)))
    {
        if(n==code)
        {
            cout<<"\n\t\tEnter quantity:";
            cin>>q;
            pos= -1 * sizeof(o1);
            fp.seekp(pos,ios::cur);
            qty=qty-q;
            fp.write((char*)&o1,sizeof(o1));
            fp.close();
            break;
        }
    }
    read();
}


void record::delete_record()
{
    int n;
    ifstream fp1;
    ofstream fp2;

    read();
    fp1.open("ice2.txt",ios::in);
    fp2.open("ice2.txt",ios::out);
    cout<<"\n\n\t\tEnter code of ice cream flavour:";
    cin>>n;

    while(fp1.read((char *)&o1,sizeof(o1)))
    {
        if(n!=code)
        {
            fp2.write((char *)&o1,sizeof(o1));
        }
        cout<<"\n\n\t\t---------Item Deleted Successfully-----------";
    }
    fp1.close();
    fp2.close();

    remove("ice2.txt");
    rename("ice2.txt","ice2.txt");

    read();
}


void ice::view()
{
	cout<<"\n"<<name;
	cout<<"\t\t";
    cout<<code;
	cout<<"\t\t";
	cout<<rate;
	cout<<"\t\t";
	cout<<qty;
}


void ice::getdata()
{

    cout<<"\nEnter ice cream flavour to be added:";
    cin>>name;
    cout<<"\nEnter ice cream flavour code to be added:";
    cin>>code;
    cout<<"\nEnter ice cream flavour price:";
    cin>>rate;
    cout<<"\nEnter the quantity:";
    cin>>qty;
}


void ice:: write()
{

    ofstream f1;
    f1.open("ice2.txt",ios::app);
    r1.getdata();

    f1.write((char*)&r1,sizeof(r1));
    f1.close();
    read();
}


void ice:: read()
{

    ifstream f1;
    f1.open("ice2.txt",ios::in);

    cout<<"\n\n"<<"Name"<<"\t\t"<<"Code"<<"\t\t"<<"Rate"<<"\t\t"<<"Quantity\n";
    cout<<"\n---------------------------------------------------------------\n";

    while(f1.read((char *)&r1,sizeof(r1)))
    {
        view();
    }

    f1.close();
}

int main()
{
    r1.menu();
	return 0;
}
