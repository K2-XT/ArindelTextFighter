//weaponsandarmor.h: Constains classes to house one initialization of weapons and armor.
#ifndef WEAPONSANDARMOR_H
#define WEAPONSANDARMOR_h
#include "heavyweapon.h"
#include "mediumweapon.h"
#include "lightweapon.h"
#include "MediumArmor.h"

//Weapons and armor classes to make sure each weapon and armor is only initialized once.
class Weapons {
public:
	static HeavyWeapon Battleaxe;
	static MediumWeapon Broadsword;
	static LightWeapon Assblade;

};

class Armors {
public:
	static MediumArmor TravelCloak;
};
#endif
