// Lukas Leyden
// 11/21/2024
// CS33211

#ifndef SOURCE_HPP
#define SOURCE_HPP
    #include <iostream>
    #include <fstream>

    #define RESOURCE_CATEGORIES 3 
    #define PROCESSES 5         
    #define LINE_DELIMITER ';'
    #define LIST_DELIMITER ','

    void printTable(int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* available);
    void processResource(char* file_name, int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* available);
    int main(int argc, char* argv[]);

#endif
