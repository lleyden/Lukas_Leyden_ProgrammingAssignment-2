// Lukas Leyden
// 11/21/2024
// CS33211

#include "../header/source.hpp"


void printTable(int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* avail) {
    std::cout << "Results after processing: " << std::endl << std::endl << std::endl;
    std::cout << "Allocated" << std::endl;
    for (int i = 0; i < PROCESSES; ++i) {
        std::cout << "P" << i << " {";
        for (int j = 0; j < RESOURCE_CATEGORIES - 1; ++j) {
            std::cout << allocated[i][j] << ", ";
        }
        std::cout << allocated[i][RESOURCE_CATEGORIES - 1];
        std::cout << "}" << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Max" << std::endl;
        for (int i = 0; i < PROCESSES; ++i) {
            std::cout << "P" << i << " {";
            for (int j = 0; j < RESOURCE_CATEGORIES - 1; ++j) {
                std::cout << max[i][j] << ", ";
            }
            std::cout << max[i][RESOURCE_CATEGORIES - 1];
            std::cout << "}" << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Available" << std::endl;
    std::cout << "{";
    for (int j = 0; j < RESOURCE_CATEGORIES - 1; ++j) {
        std::cout << avail[j] << ", ";
    }
    std::cout << avail[RESOURCE_CATEGORIES-1];
    std::cout << "}" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}


void processResource(char* file_name, int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* avail) {
    int currentProcess =  0;
    int curentResourcePosition = 0;
    std::string currentLine;
    std::ifstream resourceTable(file_name, std::ifstream::in);

    while(!resourceTable.eof()) {
        std::getline(resourceTable, currentLine, LINE_DELIMITER);
        if (std::stoi(currentLine) < 0) {
            for (int i = 0; i < RESOURCE_CATEGORIES; ++i) {
                std::getline(resourceTable, currentLine, LIST_DELIMITER);
                avail[i] = std::stoi(currentLine);
            }
            break;
        }
        currentProcess = std::stoi(currentLine);

        for (curentResourcePosition = 0; curentResourcePosition < RESOURCE_CATEGORIES; ++curentResourcePosition) {
            if (curentResourcePosition == (RESOURCE_CATEGORIES - 1))  {
                std::getline(resourceTable, currentLine, LINE_DELIMITER);
            } else {
                std::getline(resourceTable, currentLine, LIST_DELIMITER);
            }
            allocated[currentProcess][curentResourcePosition] = std::stoi(currentLine);
        }
            for (curentResourcePosition = 0; curentResourcePosition < RESOURCE_CATEGORIES; ++curentResourcePosition) {
                if (curentResourcePosition == (RESOURCE_CATEGORIES - 1))  {
                    std::getline(resourceTable, currentLine, LINE_DELIMITER);
                } else {
                    std::getline(resourceTable, currentLine, LIST_DELIMITER);
                }
                max[currentProcess][curentResourcePosition] = std::stoi(currentLine);
            }

    }
}
