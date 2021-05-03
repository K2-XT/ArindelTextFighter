#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H
#include <queue>

//Test Driver
int secondaryMain();

//Function Prototypes
int sCheck(int stat, std::queue<int>& curQueue);
void sRoll(int stat, std::queue<int>& curQueue);
int rollTotal(std::queue<int>& curQueue);
int rollKeep(int first, int keep, std::queue<int>& curQueue);
int rollDam(int first, int second, int& keep, std::queue<int>& curQueue);
int rolld10();






#endif