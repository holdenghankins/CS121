#include "name.h"
#include <string>
#include <iostream>
using namespace std;

Name::Name(string firstName, string lastName)
    : firstName(firstName), lastName(lastName) {}


Name::Name()
    : firstName(""), lastName("") {}


std::string Name::getFirstName() {
    return Name::firstName;
}

std::string Name::getLastName() {
    return Name::firstName;
}

std::string Name::getLastFirst() {
    return Name::lastName + " " + Name::firstName;
}

void Name::init(string firstName, string lastName) {
    Name::firstName = firstName;
    Name::lastName = lastName;
}

/**
 * Outputs name as "[last], [first]"
 */
void Name::printName() {
    cout << Name::firstName << " " << Name::lastName << endl;
}