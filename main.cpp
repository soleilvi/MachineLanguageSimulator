/*
By Soleil Vivero
09/30/22
*/

#include "functions.cpp"
#include <iostream>
#include <fstream>

#define FILE_NAME "Programming-Project-1.txt"
#define MAX_32BIT 4294967295

int main() {
    std::ifstream iFile(FILE_NAME);  // Where we will get our hexadecimals and operations
    std::string command;
    uint64_t hex1;
    uint64_t hex2;
    uint64_t result;

    for(int i = 0; i < 5 ; i++) {
        iFile >> command;
        iFile >> std::hex >> hex1;
        iFile >> std::hex >> hex2;

        if(command == "ADD") {  // Sets a base if-statement for more commands later
            result = addHex(hex1, hex2);
        }

        if(result > MAX_32BIT) {
            std::cout << "Result " << i + 1 << ": OVERFLOW, invalid result." << std::endl;
        } else {
            std::cout << "Result " << i + 1 << ": " << result << std::endl;
        }
    }

    iFile.close();
}