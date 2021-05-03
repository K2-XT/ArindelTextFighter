//charcreate.h: Contains Function Protoypes Necessary for the Character Creator (charcreate.cpp)
#ifndef CHARCREATE_H
#define CHARCREATE_H
#include <iostream>

//Forward Class Definiton
class Human;

//Function Prototypes
Human CCMain();
std::string changeName(std::string&);
void changeCCStats(int&, int&, int&, int&, int&, int&, int&, int&);
void changeCCSkills(Human&);
void changeCCGear(Human&);



#endif
