#pragma once
#include <iostream>

enum status {borrowed = 0, onTheShelf = 1};
const std::string statusMsg[] = {"borrowed", "avaliable"}; 

class Book{
private:
    std::string author;
    std::string category;
    unsigned int pages;
public:
    status currentStatus;
    Book();
    Book(std::string setAuthor, std::string setCategory, unsigned int setPages, status setStatus);
    friend std::ostream& operator<<(std::ostream& o, const Book& book);
};
