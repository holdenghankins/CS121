#include <string>
#include <iostream>
#include <sstream>
#include "date.h"
#include "address.h"
#include "name.h"
#include "student.h"
using namespace std;

Student::Student(Name* namePtr, Address* addressPtr, Date* birthdayPtr, Date* graduationPtr, int credits)
    : namePtr(namePtr), addressPtr(addressPtr), birthdayPtr(birthdayPtr), graduationPtr(graduationPtr), credits(credits) {}

Student::Student(string studentString)
    : namePtr(), addressPtr(), birthdayPtr(), graduationPtr(), credits(0)
{
    string dataArray[9];
    string token;
    stringstream ss(studentString);

    int i = 0;
    while (getline(ss, token, ',') && i < 9) {
        dataArray[i++] = token;
    }

    namePtr = new Name(dataArray[0], dataArray[1]);
    addressPtr = (new Address(dataArray[2], dataArray[3], dataArray[4], dataArray[5]));
    birthdayPtr = (new Date(dataArray[6]));
    graduationPtr = (new Date(dataArray[7]));
    credits = stoi(dataArray[8]);
}

Student::Student() {
    namePtr = new Name("", "");
    addressPtr = new Address("", "", "", "");
    birthdayPtr = (new Date("00/00/0000"));
    graduationPtr = (new Date("00/00/0000"));
    credits = 0;
}

Student::~Student() {
    delete namePtr;
    delete addressPtr;
    delete birthdayPtr;
    delete graduationPtr;

    namePtr = nullptr;
    addressPtr = nullptr;
    birthdayPtr = nullptr;
    graduationPtr = nullptr;
}

Name* Student::getName() {
    return Student::namePtr;
}

void Student::printStudent() {
    Student::namePtr->printName();
    Student::addressPtr->printAddress();
    cout << "DOB: ";
    Student::birthdayPtr->printDate();
    cout << "Grad: ";
    Student::graduationPtr->printDate();
    cout << "Credits: " << Student::credits << endl;
    cout << "____________________________________\n" << endl;
}