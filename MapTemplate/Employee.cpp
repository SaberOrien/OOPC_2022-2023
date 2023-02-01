#include "Employee.h"

using namespace std;

Employee::Employee(){
    name = "N/A";
    position = "N/A";
    age = 0;
}

Employee::Employee(string givenName, string givenPosition, unsigned int givenAge){
    name = givenName;
    position = givenPosition;
    age = givenAge;
}

ostream& operator<<(ostream& o, const Employee& emp){
    o << emp.name << " ";
    o << emp.position << " ";
    o << emp.age;
    return o;
}