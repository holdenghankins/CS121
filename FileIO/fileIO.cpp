#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

/**
 * NORMAL:
 * Program takes a file using the format
 * num1, num2, text
 * 
 * And parses into an output
 * "text  " * (num1 + num2)
 * 
 * BLACKBELT:
 * Uses exceptions to handle errors in input data
 * Note: I had to relearn these so they might be rough, but they work (I think)
 */

typedef struct {
    // Stores all data needed for output
    int num1;
    int num2;
    std::string text;
    bool error; // Used to transfer error in parseLine to printLine
} DataPoint_t;

/**
 * Goes through a line from file and picks out both numbers and text assuming in proper format
 * Errors in formatting and NULLPTR handled
 * 
 * @param string of line from file
 * @returns int first number (DataPoint_t.num1)
 * @returns int second number (DataPoint_t.num2)
 * @returns String text (DataPoint_t.text)
 * @returns if error was encountered (DataPoint_t.error)
 */
DataPoint_t parseLine(std::string line) {
    DataPoint_t dataPoint {0, 0, "", true};

    try {
        int charPtr = 0;
        if (line.empty()) {
            throw runtime_error("line not found");
        }

        // Records num1
        while (line[charPtr] != ',' && charPtr < line.length()) {
            dataPoint.num1 = (dataPoint.num1 * 10) + (line[charPtr] - '0'); // accounts for double digit numbers
            charPtr++;
        }
        if (charPtr >= line.length()) { // Reached end of line prematurely
            return dataPoint;
        }
        charPtr += 2; // Skips over comma and space

        // Records num2
        while (line[charPtr] != ',' && charPtr < line.length()) {
            dataPoint.num2 = (dataPoint.num2 * 10) + (line[charPtr] - '0');
            charPtr++;
        }
        if (charPtr >= line.length()) {
            return dataPoint;
        }
        charPtr += 2;

        // Builds/records text
        while (charPtr < line.length()) {
            dataPoint.text += line[charPtr];
            charPtr++;
        }
        dataPoint.error = false; // all 3 points added; valid data point

    } catch (out_of_range& e) { // Tries to scan a null index that for some reason isn't caught
        cout << "Exception: unexpected format encountered" << endl;
    } catch (runtime_error& e) { // NULL line
        cout << "Exception: line not found" << endl;
    }
    return dataPoint;
}

/**
 * Prints out text (num1 + num2) times
 * Handles errors encounted in parseLine() to allow for use of printLine(parseLine())
 * 
 * @param DataPoint_t (int, int, string, bool)
 * @returns if line was printed
 */
bool printLine(DataPoint_t dataPoint) {
    // Checks for error in data
    if (dataPoint.error) {
        return false;
    }

    int timesToPrint = dataPoint.num1 + dataPoint.num2;
    if (timesToPrint == 0) { // Used since first line is read seperately
        return true;
    }

    // Prints out each line with double spaces between them
    std::cout << dataPoint.text;
    for (int i = 2; i <= timesToPrint; i++) {
        std::cout << "  " << dataPoint.text; // double spaced like sample output
    }

    std::cout << "\n"; // formatting
    return true;
}

/**
 * Tries to open file
 * Tries to parse and print each line
 * Handles formatting and unopened file errors
 */
int main() {
    try {
        // Feel free to mess around with files and contents
        std::ifstream file;
        file.open("data.csv");
        //file.open("corrupted.csv");
        //file.open("nonexistent.csv");

        if (!file.is_open()) {
            throw runtime_error("unable to open file");
        }

        // Reads each line
        std::string line;
        while (!file.eof()) {
            std::getline(file, line);
            // Tries to parse and print line
            if (printLine(parseLine(line)) == false) { // checks if failed
                throw runtime_error("unexpected format encountered");
            }
        }
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return -1;
}