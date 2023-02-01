#include "KeyDoesNotExistException.h"

using namespace std;

keyDoesNotExistException::keyDoesNotExistException(unsigned int Key){
    std::string msg = std::to_string(Key);
    this->message += msg;
}

keyDoesNotExistException::keyDoesNotExistException(const std::string msg = ""){
    this->message += msg;
}

const char* keyDoesNotExistException::what(){
    return (this->message).c_str();
}
