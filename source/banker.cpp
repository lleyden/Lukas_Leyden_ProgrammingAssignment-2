// Lukas Leyden
// 11/21/2024
// CS33211

#include "../header/source.hpp"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Not Enough Arguments" << std::endl;
        exit(1);
    }
    char* resourceTable = argv[1];
    int allocated[PROCESSES][RESOURCE_CATEGORIES];
    int max[PROCESSES][RESOURCE_CATEGORIES];
    int available[RESOURCE_CATEGORIES];

    processResource(resourceTable, allocated, max, available);
    int finished[PROCESSES], anwser[PROCESSES], index = 0;

    for (int k = 0; k < PROCESSES; ++k) {
        finished[k] = 0;
    }
    int need[PROCESSES][RESOURCE_CATEGORIES];
    for (int i = 0; i < PROCESSES; ++i) {
        for (int j = 0; j < RESOURCE_CATEGORIES; ++j) {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    for (int k = 0; k < PROCESSES; ++k) {
        for (int currentProcess = 0; currentProcess < PROCESSES; ++currentProcess) {
            if (finished[currentProcess] == 0) {
                int flag = 0;
                for (int currentResource = 0; currentResource < RESOURCE_CATEGORIES; ++currentResource) { 
                    if (need[currentProcess][currentResource] > available[currentResource]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    anwser[index++] = currentProcess;
                    for (int finishedProcess = 0; finishedProcess < RESOURCE_CATEGORIES; ++finishedProcess) {
                        available[finishedProcess] += allocated[currentProcess][finishedProcess];
                        finished[currentProcess] = 1;
                    }
                }
            }
        }
    }
        int safeFlag = 1 ;

        for (int currentProcess = 0; currentProcess < PROCESSES; ++currentProcess) {
            if (finished[currentProcess] == 0) {
                safeFlag = 0;
                std::cout << "The sequence isn't safe" << std::endl;
                break;
            }
        }
            if (safeFlag == 1) {
                std::cout << "The sequence is safe" << std::endl;
                for (int currentProcess = 0; currentProcess < PROCESSES - 1; ++currentProcess) {
                    std::cout << " P" << anwser[currentProcess] << " ->";
                    
                }

                std::cout << " P" << anwser[PROCESSES - 1] << std::endl;
            }
    return 0;
}
