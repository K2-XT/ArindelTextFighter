//lightarmor.h: A class that inherits all variables from armor.h
#ifndef LIGHTARMOR_H
#define LIGHTARMOR_H
#include "armor.h"

//LightArmor class, redefines the variables of the Armor Parent Class.
class LightArmor : public Armor {
private:
public:
	LightArmor(std::string, std::string);
};
#endif
