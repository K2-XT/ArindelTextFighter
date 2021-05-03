//LightArmor.cpp: Constructor for LightArmor.h
#include "LightArmor.h"

//LightArmor Constructor
LightArmor::LightArmor(std::string n, std::string d) : Armor(3, 1, 0) {
	name = n;
	description = d;
}