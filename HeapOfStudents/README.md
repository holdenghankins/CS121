array months[13] = {null to align with numbered months, months}

class Date {
    - int day
    - int month
    - int year
}

class Name {
    - std::string firstName
    - std::string lastName
}

class Adress {
    - std::string street
    - std::string city
    - std::string state
    - int zip
}

class Student {
    - Name name
    - Adress Adress
    - Date birthday
    - Date gradDay
    - int credits
}

StudentData {
    File file;

    StudentData(File file) {
        this.file = file;
    }

    void loadStudents(std::vector<Student*>& students) {
        open file;
        std::string line = "";
        bool hasReachedEnd = feof(file);
        while (!hasReachedEnd) {
            char currentChar = char in file;
            while (currentChar != '\n') {
                line.append(currentChar)'
            }
            students.push_back(new Student(line));
            line = "";
        }
    }

    void printStudents(std::vector<Student*>& students) {
        for (int i = 0; i < v.students(); i++) {
            cout << students->getOutput();
        }
    }

    void showStudentNames(std::vector<Student*>& students) {
        for (int i = 0; i < v.students(); i++) {
            cout << students->getName();
        }
    }

    void findStudent(std::vector<Student*>& students, std::string lastName) {
        String name;
        for (int i = 0; i < v.students(); i++) {
            name = student->getName();
            if (name.find(lastName) == std::string::npos) {
                cout << student.getOutput;
            }
        }
    }

    void delStudents(std::vector<Student*>& students) {
        v.pop_back();
    }
    
    std::string menu() {
        cout << "0) quit\n1) print all student names\n2) print all student data\n3) find a student\n\nplease choose 0-3: ";
    }
}