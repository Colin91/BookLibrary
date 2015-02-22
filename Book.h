#ifndef BOOK_H
#define BOOK_H
#include<string>
using namespace std;


class Book
{
    private:
        string TITLE;
        string AUTHOR;
        string STORE_BUY;
        string BUFFER_SPACE;
        string CLEAR_B_SPACE;
        int GENRE;
        double PRICE_BUY;
        int INDEX;

    public:
        Book();
        void setTITLE(string TITLE_In);
        void setAUTHOR(string AUTHOR_In);
        void setSTORE(string STORE_BUY_In);
        void setBufferSpace()
        {
            string B_SPACE = "%";
            BUFFER_SPACE = B_SPACE;
        }
        void remBufferSpace()
        {
            string R_SPACE ="";
            BUFFER_SPACE = R_SPACE;
        }
        void setINDEX(int INDEX_In)
        {
            INDEX = INDEX_In;
        }
        void setPRICE_BUY(double PRICE_BUY_In)
        {
            PRICE_BUY = PRICE_BUY_In;
        }
        void setGENRE(int GENRE_In)
        {
            GENRE = GENRE_In;
        }
        string getBSPACE()
        {
            return BUFFER_SPACE;
        }
        string getTITLE()
        {
            return TITLE;
        }
        string getAUTHOR()
        {
            return AUTHOR;
        }
        string getSTORE()
        {
            return STORE_BUY;
        }
        int getINDEX()
        {
            return INDEX;
        }
        double getPRICE_BUY()
        {
            return PRICE_BUY;
        }
        int getGENRE()
        {
            return GENRE;
        }
};

#endif // BOOK_H
