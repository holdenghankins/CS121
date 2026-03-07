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
        Name* namePtr;
        Address* addressPtr;
        Date* birthdayPtr;
        Date* graduationPtr;
        int credits;
    public:
        Student(Name* namePtr, Address* addressPtr, Date* birthdayPtr, Date* graduationPtr, int credits);
        Student(std::string studentString);
        Student();
        ~Student();
        Name* getName();
        void printStudent();
        
};
#endif
//: name(name), address(address), birthday(birthday), graduation(graduation), credits(credits) {}