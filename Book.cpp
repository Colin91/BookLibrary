#include "Book.h"
#include <string>
#include <iostream>
using namespace std;

Book::Book()
{

}

void Book::setTITLE(string T_In)
{
    TITLE = T_In;
}

void Book::setAUTHOR(string A_In)
{
    AUTHOR = A_In;


}
void Book::setSTORE(string S_B_In)
{
    STORE_BUY = S_B_In;
}

