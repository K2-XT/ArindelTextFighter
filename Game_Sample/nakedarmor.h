//lightarmor.h: A class that inherits all variables from armor.h
#ifndef NAKEDARMOR_H
#define NAKEDARMOR_H
#include "armor.h"

//LightArmor class, redefines the variables of the Armor Parent Class.
class NakedArmor : public Armor {
private:
public:
	NakedArmor(std::string, std::string);
};
#endif