#include <string>
#include <iostream>
#include <sstream>
#include "date.h"
#include "address.h"
#include "name.h"
#include "student.h"
using namespace std;

Student::Student(Name name, Address address, Date birthday, Date graduation, int credits)
    : name(name), address(address), birthday(birthday), graduation(graduation), credits(credits) {}

Student::Student(string studentString)
    : name(), address(), birthday(), graduation(), credits(0)
{
    string dataArray[9];
    string token;
    stringstream ss(studentString);

    int i = 0;
    while (getline(ss, token, ',') && i < 9) {
        dataArray[i++] = token;
    }

    name = Name(dataArray[0], dataArray[1]);
    address = Address(dataArray[2], dataArray[3], dataArray[4], dataArray[5]);
    birthday = Date(dataArray[6]);
    graduation = Date(dataArray[7]);
    credits = stoi(dataArray[8]);
}

Name Student::getName() {
    return Student::name;
}

void Student::printStudent() {
    Student::name.printName();
    Student::address.printAddress();
    cout << "DOB: ";
    Student::birthday.printDate();
    cout << "Grad: ";
    Student::graduation.printDate();
    cout << "Credits: " << Student::credits << endl;
}