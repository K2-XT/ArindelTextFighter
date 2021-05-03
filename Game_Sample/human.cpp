//human.cpp: Include Implimentation for Functions of Class Human
#include "human.h"
#include "mergesort.h"
#include "globalfunctions.h"
#include "nakedarmor.h"

//Default Constructor
Human::Human() {

}

//Human Constructor
Human::Human(std::string tempName, int str, int per, int ref, int end, int cha, int intel, int agi, int luc) {
	//Set Name
	name = tempName;
	//Strength Stats/Skills
	strength = str;
	athletics = strength - 1;

	//Perception Stats/Skills
	perception = per;
	investigation = perception - 1;
	survival = perception - 1;
	rangedpowder = perception - 1;

	//Reflexes Stats/Skills
	reflexes = ref;
	thievery = reflexes - 1;
	rangedstring = reflexes - 1;

	//Endurance Stats/Skills
	endurance = end;
	heavyweapons = endurance - 1;
	rangedbolt = endurance - 1;

	//Charisma Stats/Skills
	charisma = cha;
	acting = charisma - 1;
	deception = charisma - 1;
	intimidation = charisma - 1;
	pursuasion = charisma - 1;

	//Intelligence Stats/Skills
	intelligence = intel;
	arcane = intelligence - 1;
	bargaining = intelligence - 1;
	lore = intelligence - 1;
	medicine = intelligence - 1;
	lightweapons = intelligence - 1;

	//Agility Stats/Skills
	agility = agi;
	acrobatics = agility - 1;
	mediumweapons = agility - 1;
	stealth = agility - 1;

	//Luck Stats/Skills
	luck = luc;

	setHealth();
	NakedArmor naked("Naked", "Barren Birthday-Suit");
	equipArmor(naked);
	curHealth = baseHealth;
	dynamHealth(0);
}

//int rollAttack(): When a Player Attempts to Attack Something, Calls The Weapon's Specific Attack Function
int Human::rollAttack(Human& player) {
	return eWeapon->rollA(player);
}

//int rollDamage(): When a Player Hits, Calls The Weapon's Specific Damage Function
int Human::rollDamage(Human& player) {
	return eWeapon->rollD(player);
}

//int rollInitiative(): Rolls Reflexes + Perception, Keeping Perception
int Human::rollInitiative() {
	return rollKeep(reflexes, perception, curRoll);
}

//int dynamHealth(): Keeps Track of Current Health and Sets Conditions
int Human::dynamHealth(int damage) {
	int tempH = curHealth;
	if (damage < eArmor->armRed()) {}
	else { curHealth += eArmor->armRed() - damage; }
	int nicked = baseHealth - (getEnd() * 2);
	int grazed = nicked - (getEnd() * 2);
	int hurt = grazed - (getEnd() * 2);
	int crippled = hurt - (getEnd() * 2);
	int down = crippled - (getEnd() * 2);
	int out = down - (getEnd() * 2);
	if (curHealth > nicked) {
		cond = "healthy";
	}
	else if (nicked >= curHealth && curHealth > grazed) {
		cond = "nicked";
	}
	else if (grazed >= curHealth && curHealth > hurt) {
		cond = "grazed";
	}
	else if (hurt >= curHealth && curHealth > crippled) {
		cond = "hurt";
	}
	else if (crippled >= curHealth && curHealth > down) {
		cond = "crippled";
	}
	else if (down >= curHealth && curHealth > out) {
		cond = "down";
	}
	else if (curHealth <= out) {
		cond = "out";
	}
	curDefense = dynamDefense();
	int tempH2 = curHealth;
	displayDamageTaken(tempH, tempH2);
	return curHealth;
}

//Takes two ints, subtracts the first from the second, then displays.
void Human::displayDamageTaken(int temp1, int temp2) {
	if (temp1 != temp2) {
		std::cout << name << " has taken " << temp1 - temp2 << " damage." << std::endl;
	}
}

//int condition(): Checks Condition and Returns the TN Increase
int Human::condition() {
	int TNinc = 0;
	if (cond == "nicked") {
		TNinc = 3;
	}
	else if (cond == "grazed") {
		TNinc = 5;
	}
	else if (cond == "hurt") {
		TNinc = 10;
	}
	else if (cond == "crippled") {
		TNinc = 20;
	}
	else if (cond == "down") {
		TNinc = 40;
	}
	else if (cond == "out") {
		TNinc = 50;
	}
	return TNinc;
}

//int dynamDefense(): Calculates the curDefense for the Human
int Human::dynamDefense() {
	return baseDefense - condition() + eArmor->armTN();
}

//void equipWeapon(): "equips" the human with a weapon to be used in combat functions.
void Human::equipWeapon(Weapon &w) {
	eWeapon = &w;
}

//void equipArmor(): "equips" the human with armor to be used to calculate TN.
void Human::equipArmor(Armor& arm) {
	eArmor = &arm;
	setDefense(eArmor);
	dynamHealth(0);
}

//int statCheck(): Takes in One of the Character's Stats, then Rolls the Appropriate Amount of Dice.
int Human::statCheck(int stat) {
	return sCheck(stat, curRoll);
}

//void statCheck(): Takes a Stat and Rolls the Stat's Amount of d10's, Fills a curRoll Queue with the Rolls.
void Human::statRoll(int stat) {
	sRoll(stat, curRoll);
}

//int checkTotal(): Takes the Current Rolls and Totals the Values.
int Human::checkTotal() {
	return rollTotal(curRoll);
}

//int intkintRoll: Allows For The Rolling of Two Values, Then Only Keeping the Second
int Human::intkintRoll(int first, int keep) {
	return rollKeep(first, keep, curRoll);
}
