#include "Book.h"

using namespace std;

Book::Book(){
    author = "N/A";
    category = "N/A";
    pages = 0;
    currentStatus = borrowed;
}

Book::Book(string setAuthor, string setCategory, unsigned int setPages, status setStatus){
    author = setAuthor;
    category = setCategory;
    pages = setPages;
    currentStatus = setStatus;
}

ostream& operator<<(ostream& o, const Book& book){
    o << book.author << " ";
    o << book.category << " ";
    o << book.pages << " ";
    o << statusMsg[book.currentStatus];
    return o;
}
