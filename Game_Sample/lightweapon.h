//lightweapon.h: Holds the Class HeavyWeapon. Inherits from weapon.h
#ifndef LIGHTWEAPON_H
#define LIGHTWEAPON_H
#include "weapon.h"

//Forward Class Definition
class Human;

//Class LightWeapon: Inherits from Weapon. Constains Constructors and Functions
class LightWeapon : public Weapon {
private:
	std::string associatedSkill = "Light Weapons";
	std::string associatedStat = "Intelligence";
public:
	LightWeapon();
	LightWeapon(std::string, int, int, std::string);
	int rollA(Human& player) override;
	int rollD(Human& player) override;
};

#endif
