#include "address.h"
#include <string>
#include <iostream>
using namespace std;

Address::Address(string street, string city, string state, string zip)
    : street(street), city(city), state(state), zip(zip) {}

Address::Address()
    : street(""), city(""), state(""), zip("") {}

void Address::init(string street, string city, string state, string zip) {
    Address::street = street;
    Address::city = city;
    Address::state = state;
    Address::zip = zip;
}

string Address::getStreet() {
    return Address::street;
}

string Address::getCity() {
    return Address::city;
}

string Address::getState() {
    return Address::state;
}

string Address::getZip() {
    return Address::zip;
}

/**
 * Prints address using format "[street]\n[city] [state], [zip]"
 */
void Address::printAddress() {
    cout << Address::street << "\n" << Address::city << " " << Address::state << ", " << Address::zip << endl;
}