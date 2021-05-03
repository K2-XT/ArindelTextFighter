//weapon.h: The Abstract Class Weapon
#ifndef WEAPON_H
#define WEAPON_H
#include "damage.h"
#include <string>
#include <queue>

//Forward Class Definition
class Human;

//Abstract Class Weapon: Contains the Functions to Roll Attack and Roll Damage
class Weapon {
protected:
	std::string name = "Default";
	std::string associatedSkill = "NULL";
	std::string associatedStat = "NULL";
	std::string description = "Default";
	std::queue<int> hwRoll;
	Damage dam;
public:
	std::string wepName() { return name; }
	std::string wepDescript() { return description; }
	virtual int rollA(Human& player) = 0;
	virtual int rollD(Human& player) = 0;
};

#endif
