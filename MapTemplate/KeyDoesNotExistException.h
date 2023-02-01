#pragma once
#include <iostream>

class keyDoesNotExistException : public std::exception{
private:
    std::string message = "Thrown Key Does Not Exist Exception for key ";
public:
    keyDoesNotExistException(unsigned int Key);
    keyDoesNotExistException(const std::string msg);
    const char* what();
};
