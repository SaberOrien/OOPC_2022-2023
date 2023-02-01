#pragma once
#include <iostream>

class Employee{
private:
    std::string name;
public:
    std::string position;
    unsigned int age;
    Employee();
    Employee(std::string givenName, std::string givenPosition, unsigned int givenge);
    friend std::ostream& operator<< (std::ostream& o, const Employee& emp);
};