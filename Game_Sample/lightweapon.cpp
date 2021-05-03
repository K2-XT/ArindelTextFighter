//lightweapon.cpp: Contains HeavyWeapon Class. Inherits from weapon.h
#include "human.h"
#include "lightweapon.h"
#include "damage.h"
#include "globalfunctions.h"
#include <iostream>

//Default Constructor
LightWeapon::LightWeapon() {

}

//Constructor
LightWeapon::LightWeapon(std::string n, int r, int k, std::string d) {
	name = n;
	dam.roll = r;
	dam.keep = k;
	description = d;
}

//int LightWeapon::rollA(): Rolls Attack (When A Human Tries to Hit Something)
int LightWeapon::rollA(Human& player) {
	return rollKeep(player.getLightweapons(), player.getAgi(), hwRoll);
}

//int LightWeapon::rollD(): Rolls Damage (If The Human Hits Something, Rolls To See How Much Damge Inflicted)
int LightWeapon::rollD(Human& player) {
	int roll;
	roll = rollDam(player.getIntel(), dam.roll, dam.keep, hwRoll);
	return roll;
}