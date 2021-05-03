//armor.h: Defines the Abstract Class Armor
#ifndef ARMOR_H
#define ARMOR_H
#include <string>

//Abstract Class Armor. LightArmor and MediumArmor are Inheriters
class Armor {
protected:
	std::string name;
	std::string description;
	const int TNinc;
	const int red;
	const int mod;
public:
	Armor(const int tn, const int r, const int m) : TNinc(tn), red(r), mod(m)  {}
	std::string armName() { return name; }
	std::string armDesc() { return description; }
	virtual int armMod() { return mod; }
	virtual int armTN() { return TNinc; }
	virtual int armRed() { return red; }
};
#endif
