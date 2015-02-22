#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "Book.h"
#include "BookList.h"
using namespace std;


char X;
int ListCounter = 0;
int BookCounter = 0;
int Search;
int MIN = 0;
int MAX = 1000;

struct BookDef
{
    string Title,Author,Store;
    int Genre;
    double Price;
};

bool isEmpty();
bool isFull();
string S;
int GENRE;





int main()
{
    Book BookOB;
    Book BOOKLIST[1000];
    Book *PTR;
    BookDef BD;
    PTR = &BOOKLIST[0];
    Book *COUNTER;
    COUNTER = &BOOKLIST[0];
    BookList BKL(PTR,MAX);
    ofstream file;
    fstream zile;
    string buffer,buffer1,buffer2;
    string T,A,SB;
    string Full("");
    int I,G;
    int COUNT=0;
    int Proxy = 0;
    double PB;
    stringstream ss;
    int flag;

    zile.open("Books.txt",ios::in);
    getline(zile,buffer1);
    ss<<buffer1;
    ss>>COUNT;

    if(COUNT==0)
    {
        flag=0;
    }
    else
    {
        flag=1;
    }


    if(flag==1)
    {
        do
        {
            getline(zile,buffer);
            istringstream istr1(buffer);

            istr1>>I;
            //istr1>>T;
            do
            {
                T.clear();
                istr1>>T;
                if(T == "%")
                {
                    T=="%";
                }
                else
                {
                    Full += (T);
                    Full += " ";

                }

            }while(T != "%");
            BD.Title = Full;
            Full.clear();
            T.clear();

            //istr1>>A;
            do
            {
                A.clear();
                istr1>>A;
                if(A == "%")
                {
                    A=="%";
                }
                else
                {
                    Full += (A);
                    Full += " ";

                }

            }while(A != "%");
            BD.Author = Full;
            Full.clear();
            A.clear();


            istr1>>G;
            BD.Genre = G;
            //istr1>>SB;
            do
            {
                SB.clear();
                istr1>>SB;
                if(SB == "%")
                {
                    SB=="%";
                }
                else
                {
                    Full += (SB);
                    Full += " ";

                }

            }while(SB != "%");
            BD.Store = Full;
            Full.clear();
            SB.clear();




            istr1>>PB;
            BD.Price = PB;

            BookOB.setTITLE(BD.Title);
            BookOB.setAUTHOR(BD.Author);
            BookOB.setGENRE(BD.Genre);
            BookOB.setSTORE(BD.Store);
            BookOB.setPRICE_BUY(BD.Price);
            BookOB.setINDEX(I);
            ListCounter++;
            BKL.Add(BookOB);
            PTR = &BOOKLIST[ListCounter];
            //cout<<buffer;
            buffer="";
            Proxy++;

        }while(Proxy != COUNT);
    }
    zile.close();


    cout<<endl;
    system("Color 1A");
    cout<<"===================================================================="<<endl;
    cout<<"=================B  O  O  K    L  I  B  R  A  R  Y=================="<<endl;
    cout<<"===================================================================="<<endl;
    cout<<""<<endl;
    cout<<"[------MAIN MENU------]"<<endl;
    cout<<"[0] List Books: "<<endl;
    cout<<"[1] Add Book: "<<endl;
    cout<<"[2] Remove Book: "<<endl;
    cout<<"[3] Search Books: "<<endl;
    cout<<"[4] Show Genre: "<<endl;
    cout<<"[5] Edit Book"<<endl;
    cout<<"[x] Exit: "<<endl;

    cout<<"Enter Choice : " <<endl;
    cin>>X;


    do
    {

        if(X == '0')
        {
            for(int i=0;i<ListCounter;i++)
            {
                BKL.getBook(i);

            }

        }
        if(X == '1')
        {

            cout<<"[1]================================================"<<endl;
            cout<<"Sub Menu - ADD BOOK"<<endl;
            if(BKL.isFull() == false)
            {
                cin.ignore();
                cout<<"[ Set Title   : ";
                getline(cin,BD.Title);


                BookOB.setTITLE(BD.Title);

               //cin.ignore();
                cout<<"| Set Author  : ";
                getline(cin,BD.Author);

                BookOB.setAUTHOR(BD.Author);




                cout<<"   [ Adventure  : (1)  Biography  : (5)  Classics : (9)   Computing: (13)  ]"<<endl;
                cout<<"   | Crime      : (2)  Economics  : (6)  Fiction  : (10)  History  : (14)  |"<<endl;
                cout<<"   | Horror     : (3)  Philosophy : (7)  Poetry   : (11)  Politics : (15)  |"<<endl;
                cout<<"   [ Religion   : (4)  Sci-Fiction: (8)  Finance  : (12)  War      : (16)  ]"<<endl;
                cout<<"";
                cout<<"| Genre: ";
                cin>>BD.Genre;
                GENRE = BD.Genre;
                BookOB.setGENRE(GENRE);
                //S = GENREs(GENRE);


                cin.ignore();
                cout<<"| Store Bought : ";
                getline(cin,BD.Store);
                BookOB.setSTORE(BD.Store);


                cout<<"| Price Bought : ";
                cin>>BD.Price;
                double P = BD.Price;
                BookOB.setPRICE_BUY(P);

                BookCounter++;
                cout<<"[ Index Set    : " << BookCounter;
                BookOB.setINDEX(BookCounter); //SET to 0 // PUT '1' into array[0]

                cout<<""<<endl;
                cout<<"[=================================================="<<endl;
                BKL.Add(BookOB);
                PTR = &BOOKLIST[ListCounter];
                ListCounter++;


            }
            else
            {
                cout<<"List is full"<<endl;
            }
        }
        if(X == '2')
        {

            cout<<"[2]================================================"<<endl;
            cout<<"Sub Menu - REMOVE BOOK"<<endl;
            cout<<"Enter Book ID: "<<endl;
            cin>>Search;
            BKL.Remove(Search);
            if(BKL.isEmpty() == false)
            {
                cout<<"Book successfully removed  "<< BOOKLIST[Search-1].getINDEX();
                for(int t=Search; t<BookCounter; t++)
                {
                    BookOB.setINDEX(Search);
                }
                ListCounter--;
            }
            else
            {
                cout<<"List is Empty";
            }

        }
        if(X == '3')
        {
            cout<<"Enter Book Index: "<<endl;
            cin>>Search;
            BKL.getBook(Search-1);
            cout<<endl;


        }

        if(X == '4')
        {
            cout<<"Genre: "<<endl;
            cout<<"   [ Adventure  : (1)  Biography  : (5)  Classics : (9)   Computing: (13)  ]"<<endl;
            cout<<"   | Crime      : (2)  Economics  : (6)  Fiction  : (10)  History  : (14)  |"<<endl;
            cout<<"   | Horror     : (3)  Philosophy : (7)  Poetry   : (11)  Politics : (15)  |"<<endl;
            cout<<"   [ Religion   : (4)  Sci-Fiction: (8)  Finance  : (12)  War      : (16)  ]"<<endl;

        }


        cout<<"===MAIN MENU==="<<endl;
        cout<<"Enter Choice : " <<endl;
        cin>>X;

        if(X == '5')
        {

        }



    }while(X != 'x');
    //LPT = &BOOKLIST[0];

    file.open("Books.txt"); // It has to return a counter to ADJUSTS the Array.
    file<<ListCounter<<endl;
    for(int i=0;i<ListCounter;i++)
    {
        file<<" "<<COUNTER[i].getINDEX();
        file<<" "<<COUNTER[i].getTITLE();
        file<<" %";
        file<<" "<<COUNTER[i].getAUTHOR();
        file<<" %";
        file<<" "<<COUNTER[i].getGENRE();
        file<<" "<<COUNTER[i].getSTORE();
        file<<" %";
        file<<" "<<COUNTER[i].getPRICE_BUY()<<endl;


    }


    file.close();

    return 0;
}




