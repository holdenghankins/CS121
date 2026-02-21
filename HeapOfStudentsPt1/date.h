//date.h
#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS
#include <string>
#include <iostream>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
public:
    Date(int month, int day, int year);
    Date(std::string dateAsString);
    Date();
    void init(std::string dateAsString);
    int getDay();
    std::string getMonth();
    int getYear();
    void printDate();
};
#endif