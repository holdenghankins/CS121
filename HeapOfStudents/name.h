//name.h
#ifndef NAME_H_EXISTS
#define NAME_H_EXISTS
#include <string>
#include <iostream>
using namespace std;

class Name {
private:
    std::string firstName;
    std::string lastName;
public:
    Name(std::string firstName, std::string lastName);
    Name();
    void init(std::string firstName, std::string lastName);
    std::string getFirstName();
    std::string getLastName();
    std::string getLastFirst();
    void printName();
};
#endif