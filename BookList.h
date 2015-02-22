#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.h"


class BookList
{
    private:
        int SIZE;
        int TOTAL;
        Book *POINT;
        Book *LASTP;
        Book ARRAY[];
        Book obj;
        string s;

    public:
        BookList(Book *POINT,int);
        //void BookL(int,int);
        void Add(Book obj);
        bool Remove(int);
        int getBook(int);
        bool isEmpty();
        bool isFull();
        //string GENREs(int);


};

#endif // BOOKLIST_H
