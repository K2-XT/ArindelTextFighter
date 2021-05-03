//heavyweapon.h: Holds the Class HeavyWeapon. Inherits from weapon.h
#ifndef HEAVYWEAPON_H
#define HEAVYWEAPON_H
#include "weapon.h"

//Forward Class Definition
class Human;

//Class HeavyWeapon: Inherits from Weapon. Constains Constructors and Functions
class HeavyWeapon : public Weapon {
private:
	std::string associatedSkill = "Heavy Weapons";
	std::string associatedStat = "Strength";
public:
	HeavyWeapon();
	HeavyWeapon(std::string, int, int, std::string);
	int rollA(Human& player) override;
	int rollD(Human& player) override;
};

#endif
