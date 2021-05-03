//mediumarmor.h: A class that inherits all variables from armor.h
#ifndef MEDIUMARMOR_H
#define MEDIUMARMOR_H
#include "armor.h"

//MediumArmor class, redefines the variables of the Armor Parent Class.
class MediumArmor : public Armor {
private:
public:
	MediumArmor(std::string, std::string);
};
#endif

