//address.h
#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS
#include <string>
#include <iostream>
using namespace std;

class Address {
private:
    string street;
    string city;
    string state;
    string zip;
public:
    Address(string street, string city, string state, string zip);
    Address();
    void init(string street, string city, string state, string zip);
    string getStreet();
    string getCity();
    string getState();
    string getZip();
    void printAddress();
};
#endif