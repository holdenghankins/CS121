//student.h
#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS
#include <string>
#include <iostream>
#include "date.h"
#include "address.h"
#include "name.h"
using namespace std;

class Student {
    private:
        Name name;
        Address address;
        Date birthday;
        Date graduation;
        int credits;
    public:
        Student(Name name, Address address, Date birthday, Date graduation, int credits);
        Student(std::string studentString);
        Name getName();
        void printStudent();
        
};
#endif
//: name(name), address(address), birthday(birthday), graduation(graduation), credits(credits) {}