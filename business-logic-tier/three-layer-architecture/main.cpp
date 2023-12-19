#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "../../presentation-tier/frontend.h"

int main() {


    std::ifstream inputFile("../../data-tier/data.txt");

    std::string searchName;
    std::string searchPassword;

    int id = 0;
    
    DrawStart();

    std::cout << std::endl << std::setw(25) << "Enter username:";
    std::cin >> searchName;

    std::cout << std::setw(25) << "Enter password:";
    std::cin >> searchPassword;

    std::string line;

    bool nameFound = false;
    bool passwordFound = false;
    bool found = false;

    while (std::getline(inputFile, line)) {

        if (line.find("id") != std::string::npos) {
            id++;
        }
        if (!nameFound && line.find("username" + std::to_string(id) + ": " + searchName) != std::string::npos) {
            nameFound = true;
        }

        if (!passwordFound && line.find("password" + std::to_string(id) + ": " + searchPassword) != std::string::npos) {
            passwordFound = true;
        }

        if (nameFound && passwordFound) {
            found = true;
        }
    }

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    if (found) {
        std::cout << std::endl << std::setw(25) << "Entry found.";
    }
    else {
        std::cout << std::endl << std::setw(25) << "Entry not found.";
    }

    std::cout << std::endl;

    DrawEnd();

    inputFile.close();
}