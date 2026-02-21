#include "date.h"
#include <string>
#include <iostream>
using namespace std;

Date::Date(int month, int day, int year) 
    : month(month), day(day), year(year) {}

/**
 * Parses a string formatted "mm/dd/yyyy"
 */
Date::Date(string dateAsString)
    : month(((dateAsString[0] - '0') * 10) + (dateAsString[1] - '0')),
    day(((dateAsString[3] - '0') * 10) + (dateAsString[4] - '0')),
    year(((dateAsString[6] - '0') * 1000) + ((dateAsString[7] - '0') * 100) + 
    ((dateAsString[8] - '0') * 10) + (dateAsString[9] - '0')) {}

Date::Date()
    : month(0), day(0), year(0) {}

void Date::init(string dateAsString) {
    Date::month = ((dateAsString[0] - '0') * 10) + (dateAsString[1] - '0');
    Date::day = ((dateAsString[3] - '0') * 10) + (dateAsString[4] - '0');
    Date::year = ((dateAsString[6] - '0') * 1000) + ((dateAsString[7] - '0') * 100) + 
    ((dateAsString[8] - '0') * 10) + (dateAsString[9] - '0');
}

string Date::getMonth() {
    string monthsArr[13] = {"", "January", "Febuary", "March", "April", "May", "June", "July", "August", "September",
    "October", "November", "December"}; // [0] is blank so date numbers match up with index
    return monthsArr[Date::month]; 
}

int Date::getDay() {
    return Date::day;
}

int Date::getYear() {
    return Date::year;
}

/**
 * Ouputs date in format "[month as word] [day], [year]"
 */
void Date::printDate() {
    string monthsArr[13] = {"", "January", "Febuary", "March", "April", "May", "June", "July", "August", "September",
    "October", "November", "December"};
    cout << monthsArr[Date::month] << " " << Date::day << ", " << Date::year << endl;
}