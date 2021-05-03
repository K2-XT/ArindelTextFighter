//nakearmor.cpp: Default armor if characters are never equipped with armor.
#include "nakedarmor.h"

//NakedArmor class for default armor.
NakedArmor::NakedArmor(std::string n, std::string d) : Armor(0, 0, 0) {
	name = n;
	description = d;
}