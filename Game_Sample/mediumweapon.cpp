//mediumweapon.cpp: Contains HeavyWeapon Class. Inherits from weapon.h
#include "human.h"
#include "MediumWeapon.h"
#include "damage.h"
#include "globalfunctions.h"
#include <iostream>

//Default Constructor
MediumWeapon::MediumWeapon() {

}

//Constructor
MediumWeapon::MediumWeapon(std::string n, int r, int k, std::string d) {
	name = n;
	dam.roll = r;
	dam.keep = k;
	description = d;
}

//int MediumWeapon::rollA(): Rolls Attack (When A Human Tries to Hit Something)
int MediumWeapon::rollA(Human& player) {
	return rollKeep(player.getMediumweapons(), player.getAgi(), hwRoll);
}

//int MediumWeapon::rollD(): Rolls Damage (If The Human Hits Something, Rolls To See How Much Damge Inflicted)
int MediumWeapon::rollD(Human& player) {
	int roll;
	roll = rollDam(player.getEnd(), dam.roll, dam.keep, hwRoll);
	return roll;
}