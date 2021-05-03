#ifndef HUMAN_H
#define HUMAN_H
#include "weapon.h"
#include "armor.h"
#include <iostream>
#include <string>
#include <queue>

class Armor;

class Human {
private:
	//Name
	std::string name;

	//Stats
	int strength;
	int perception;
	int reflexes;
	int endurance;
	int charisma;
	int intelligence;
	int agility;
	int luck;
	int baseHealth;
	int curHealth;
	int baseDefense;
	int curDefense;
	std::string cond;
	int defense;

	//Queue for Storing Dice Rolls
	std::queue<int> curRoll;

	//Skills
	int acrobatics = 1;
	int acting = 1;
	int arcane = 1;
	int athletics = 1;
	int bargaining = 1;
	int deception = 1;
	int heavyweapons = 1;
	int lightweapons = 1;
	int lore = 1;
	int intimidation = 1;
	int investigation = 1;
	int medicine = 1;
	int mediumweapons = 1;
	int pursuasion = 1;
	int rangedbolt = 1;
	int rangedpowder = 1;
	int rangedstring = 1;
	int stealth = 1;
	int survival = 1;
	int thievery = 1;

	//Weapons and Armor
	Weapon* eWeapon;
	Armor* eArmor;

public: 
	Human();
	Human(std::string, int, int, int, int, int, int, int, int);
	int rollAttack(Human&);
	int rollDamage(Human&);
	int rollInitiative();
	int dynamHealth(int);
	int condition();
	int dynamDefense();
	void setDefense(Armor* &arm) { baseDefense = (getRef() * 5) + 5 + arm->armTN(); }
	void setHealth() { baseHealth = getEnd() * 20; };
	void displayDamageTaken(int, int);
	std::string getCond() { return cond; }
	/*void levelUp();*/
	
	//Name Getter
	std::string getName() { return name; }

	//Stat Getters
	int getStr() { return strength; }
	int getPer() { return perception; }
	int getRef() { return reflexes; }
	int getEnd() { return endurance; }
	int getChar() { return charisma; }
	int getIntel() { return intelligence; }
	int getAgi() { return agility; }
	int getLuck() { return luck; }

	//Skill Getters
	int getAcrobatics() { return acrobatics; }
	int getActing() { return acting; }
	int getArcane() { return arcane; }
	int getAthletics() { return athletics; }
	int getBargaining() { return bargaining; }
	int getDeception() { return deception; }
	int getHeavyweapons() { return heavyweapons; }
	int getLightweapons() { return lightweapons; }
	int getLore() { return lore; }
	int getIntimidation() { return intimidation; }
	int getInvestigation() { return investigation; }
	int getMedicine() { return medicine; }
	int getMediumweapons() { return mediumweapons; }
	int getPursuasion() { return pursuasion; }
	int getRangedbolt() { return rangedbolt; }
	int getRangedpowder() { return rangedpowder; }
	int getRangedstring() { return rangedstring; }
	int getStealth() { return stealth; }
	int getSurvival() { return survival; }
	int getThievery() { return thievery; }

	//Skill Incrementors (For Leveling Up)
	void incAcrobatics() { acrobatics++; }
	void incActing() { acting++; }
	void incArcane() { arcane++; }
	void incAthletics() { athletics++; }
	void incBargaining() { bargaining++; }
	void incDeception() { deception++; }
	void incHeavyweapons() { heavyweapons++; }
	void incLightweapons() { lightweapons++; }
	void incLore() { lore++; }
	void incIntimidation() { intimidation++; }
	void incInvestigation() { investigation++; }
	void incMedicine() { medicine++; }
	void incMediumweapons() { mediumweapons++; }
	void incPursuasion() { pursuasion++; }
	void incRangedbolt() { rangedbolt++; }
	void incRangedpowder() { rangedpowder++; }
	void incRangedstring() { rangedstring++; }
	void incStealth() { stealth++; }
	void incSurvival() { survival++; }
	void incThievery() { thievery++; }



	//TN Getters
	int getHealth() { return curHealth; }
	int getDefense() { return baseDefense; }
	
	//Weapons and Armor
	void equipWeapon(Weapon&);
	void equipArmor(Armor&);
	std::string getArmorName() { return eArmor->armName(); }
	std::string getWeaponName() { return eWeapon->wepName(); }

	//Rolling Functions
	int statCheck(int);
	void statRoll(int);
	int checkTotal();
	int intkintRoll(int, int);

	
	
};

#endif
