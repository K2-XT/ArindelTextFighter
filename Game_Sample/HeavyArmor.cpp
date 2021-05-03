//HeavyArmor.cpp: Contains the constructor for the Heavyarmor class, defined by HeavyArmor.h
#include "HeavyArmor.h"

//Constructor
HeavyArmor::HeavyArmor(std::string n, std::string d) : Armor(10, 5, 5) {
	name = n;
	description = d;
}