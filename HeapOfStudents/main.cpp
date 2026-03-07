#include <iostream>
#include "date.h"
#include "address.h"
#include "student.h"
#include <vector>
#include <fstream>
using namespace std;

bool loadStudents(vector<Student*>&, string);
void printStudents(vector<Student*>&);
void showStudentNames(vector<Student*>&);
void findStudent(vector<Student*>&);
void delStudents(vector<Student*>&);
char menu();


int main(){
  vector<Student*> students;
  if (loadStudents(students, "students.csv") == false) { // attempts to open file, ends program if failed
    return 0;
  }

  /* 
  Loops main menu prompt until exited by user
  Done in main to avoid recursive calls which could be used to overload stack
  */
  bool looper = true;
  while (looper) {
    switch(menu())
    {
      case '0':
        looper = false;
        break;
      case '1':
        showStudentNames(students);
        break;
      case '2':
        printStudents(students);
        break;
      case '3':
        findStudent(students);
        break;
      default:
        cout << "invalid input" << endl;
    }
  }
  // Cleanup
  delStudents;
} // end main

/**
 * Opens a csv and reads all student data into the vector
 */
bool loadStudents(vector<Student*>& students, string fileName) {
  if (fileName.empty()) {
    cout << "No file name recieved";
  }
  ifstream file(fileName); 

  // Checks if file is open
  if (!file.is_open()) {
    cout << "Unable to open file";
    return false;
  }

  // All line parsing is done in the Student class
  string line;
  while (getline(file, line)) {
    students.push_back(new Student(line));
  }
  return true;
}

/**
 * Prints all student data
 */
void printStudents(vector<Student*>& students) {
  for (int i = 0; i < students.size(); i++) {
    students[i]->printStudent();
  }
}

/**
 * Prints all students as "last, first\n"
 */
void showStudentNames(vector<Student*>& students) {
  Name* name;
  for (int i = 0; i < students.size(); i++) {
    name = students[i]->getName();
    cout << name->getLastFirst() << endl;
  }
  cout << "____________________________________" << endl;
  name = nullptr;
}

/**
 * Asks student for a last name and finds all instances of that being a substring of a last name
 * Prints data for each student found
 */
void findStudent(vector<Student*>& students) {
  string nameToFind;
  cout << "last name of student: ";
  cin >> nameToFind;
  cout << endl;

  bool nameFound = false;
  Name* name;
  for (int i = 0; i < students.size(); i++) {
    name = students[i]->getName();
    if (name->getLastName().find(nameToFind) != string::npos) { // "string::npos" means no match found in .find()'s documentation
      nameFound = true;
      students[i]->printStudent();
    }
  }

  // Notifies user no result
  if (nameFound == false) {
    cout << "No matching student was found" << "____________________________________" << endl;
  }
}

/**
 * Deletes all students stored in vector
 */
void delStudents(std::vector<Student*>& students) {
  for (int i = 0; i < students.size(); i++) {
    delete students.back();
    students.back() = nullptr;
    students.pop_back();
  }
}

/**
 * Main 4 input menu as specified in the handout
 */
char menu() {
  char input;
  cout << "0) quit\n1) print all student names\n2) print all student data\n3) find a student\n\nplease choose 0-3: ";
  cin >> input;
  return input;
}