//MediumArmor.h: Inherits from armor.h
#include "MediumArmor.h"

//MediumArmor Class Constructor
MediumArmor::MediumArmor(std::string n, std::string d) : Armor(5, 3, 3) {
	name = n;
	description = d;
}