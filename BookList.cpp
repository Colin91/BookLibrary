#include "BookList.h"
#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

BookList::BookList(Book *BK, int SIZEIN) // THE address of the FIRST index ARRAY[0] is passed.
:POINT(BK)
{
    LASTP = BK; // THIS ARRAY[0] stays fixed
    SIZE = SIZEIN;
    TOTAL = 0;
}

void BookList::Add(Book BK1)
{
    obj = BK1;
    POINT[TOTAL] = obj;
    TOTAL++;
}

string GENREs(int G)
{
    string GEN;
    if(G==1)
    {
        GEN  = "Adventure";
    }
    if(G==2)
    {
        GEN  = "Crime";
    }
    if(G==3)
    {
        GEN  = "Horror";
    }
    if(G==4)
    {
        GEN  = "Religion";
    }
    if(G==5)
    {
        GEN  = "Biography";
    }
    if(G==6)
    {
        GEN  = "Economics";
    }
    if(G==7)
    {
        GEN  = "Philosophy";
    }
    if(G==8)
    {
        GEN  = "Sci-Fiction";
    }
    if(G==9)
    {
        GEN  = "Classics";
    }
    if(G==10)
    {
        GEN  = "Fiction";
    }
    if(G==11)
    {
        GEN  = "Poetry";
    }
    if(G==12)
    {
        GEN  = "Finance";
    }
    if(G==13)
    {
        GEN  = "Computing";
    }
    if(G==14)
    {
        GEN  = "History";
    }
    if(G==15)
    {
        GEN  = "Politics";
    }
    if(G==16)
    {
        GEN  = "War";
    }
    return GEN;
}


int BookList::getBook(int i)
{
     //cout<<"INSIDE BOOKLIST.CPP " << POINT[i].getINDEX() << "\n";

     cout<< "[ Index  : " << POINT[i].getINDEX()<<endl;
     cout<< "| Title  : " << POINT[i].getTITLE()<<endl;
     cout<< "| Author : " << POINT[i].getAUTHOR()<<endl;
     cout<< "| Store  : " << POINT[i].getSTORE()<<endl;
     string s = GENREs(POINT[i].getGENRE());
     cout<< "| Genre  : " << s << endl;
     cout<< "[ Price  : " << POINT[i].getPRICE_BUY()<<endl;
     cout<<"-----------------------------------------"<<endl;
     int j = POINT[i].getINDEX();
     return j;
}

bool BookList::Remove(int searchIN)
{
    bool SWI;
    searchIN = searchIN-1;
    if(TOTAL!=0)
    {

        for(int j=0;j<TOTAL;j++)
        {
             int Local = POINT[j].getINDEX();

             if(Local == searchIN)
             {
                POINT[searchIN] = POINT[searchIN+1];
                for(int p = searchIN; p<TOTAL; p++)
                {
                    POINT[p] = POINT[p+1];
                }
             }
        }
        LASTP = &ARRAY[0];
        TOTAL--;
        SWI = true;

    }
    else
    {
        SWI = false;
    }

      //}
    return SWI;

}

bool BookList::isEmpty()
{
    bool SWI;
    if(TOTAL==0)
    {
        SWI = true;
    }
    else
    {
        SWI = false;
    }
    return SWI;
}
bool BookList::isFull()
{
    bool SWI;
    if(TOTAL == SIZE)
    {
        SWI = true;
    }
    else
    {
        SWI = false;
    }
    return SWI;

}


