//mediumweapon.h: Holds the Class HeavyWeapon. Inherits from weapon.h
#ifndef MEDIUMWEAPON_H
#define MEDIUMWEAPON_H
#include "weapon.h"

//Forward Class Definition
class Human;

//Class MediumWeapon: Inherits from Weapon. Constains Constructors and Functions
class MediumWeapon : public Weapon {
private:
	std::string associatedSkill = "Medium Weapons";
	std::string associatedStat = "Endurance";
public:
	MediumWeapon();
	MediumWeapon(std::string, int, int, std::string);
	int rollA(Human& player) override;
	int rollD(Human& player) override;
};

#endif