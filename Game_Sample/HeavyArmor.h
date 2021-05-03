//heavyarmor.h: A class that inherits all variables from armor.h
#ifndef HEAVYARMOR_H
#define HEAVYARMOR_H
#include "armor.h"


//HeavyArmor class, redefines the variables of the Armor Parent Class.
class HeavyArmor : public Armor {
private:
public:
	HeavyArmor(std::string, std::string);
};
#endif

