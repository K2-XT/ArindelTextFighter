//heavyweapon.cpp: Contains HeavyWeapon Class. Inherits from weapon.h
#include "human.h"
#include "heavyweapon.h"
#include "damage.h"
#include "globalfunctions.h"
#include <iostream>

//Default Constructor
HeavyWeapon::HeavyWeapon() {

}

//Constructor
HeavyWeapon::HeavyWeapon(std::string n, int r, int k, std::string d) {
	name = n;
	dam.roll = r;
	dam.keep = k;
	description = d;
}


//int HeavyWeapon::rollA(): Rolls Attack (When A Human Tries to Hit Something)
int HeavyWeapon::rollA(Human& player) {
	return rollKeep(player.getHeavyweapons(), player.getEnd(), hwRoll);
}

//int HeavyWeapon::rollD(): Rolls Damage (If The Human Hits Something, Rolls To See How Much Damge Inflicted)
int HeavyWeapon::rollD(Human& player) {
	int roll;
	roll = rollDam(player.getStr(), dam.roll, dam.keep, hwRoll);
	return roll;
}