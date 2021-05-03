//charcreate.cpp: Allows the User to Create Their Player Character
#include "charcreate.h"
#include "human.h"
#include "weaponsandarmor.h"

//CCMain(): The Main Function of the Character Creator. Makes the Process User Friendly and Calls Human Stat-Changing Functions
Human CCMain() {
	std::string tempName;
	changeName(tempName);
	int tempStr = 1;
	int tempPer = 1;
	int tempRef = 1;
	int tempEnd = 1;
	int tempCha = 1;
	int tempIntel = 1;
	int tempAgi = 1;
	int tempLuc = 1;
	changeCCStats(tempStr, tempPer, tempRef, tempEnd, tempCha, tempIntel, tempAgi, tempLuc);
	std::cout << "Character: " << tempName << std::endl;
	Human player(tempName, tempStr, tempPer, tempRef, tempEnd, tempCha, tempIntel, tempAgi, tempLuc);
	changeCCSkills(player);
	changeCCGear(player);
	return player;
}

//changeName(): Changes the Human Player Name
std::string changeName(std::string &tempName) {
	std::cout << "Please Enter a Name: ";
	std::cin >> tempName;
	system("CLS");
	return tempName;
}

//changeCCStats(): Allows User to Input Human Player Base Stats
void changeCCStats(int& str, int& per, int& ref, int& end, int& cha, int& intel, int& agi, int& luc) {
	int tempPoints = 25;
	int option;
	while (tempPoints != 0) {
		std::cout << "Assign Your Stats: " << std::endl;
		std::cout << "Points Remaining: " << tempPoints << std::endl;
		std::cout << "1: Strength: " << str << std::endl;
		std::cout << "2: Perception: " << per << std::endl;
		std::cout << "3: Reflexes : " << ref << std::endl;
		std::cout << "4: Endurance: " << end << std::endl;
		std::cout << "5: Charisma: " << cha << std::endl;
		std::cout << "6: Inteligence: " << intel << std::endl;
		std::cout << "7: Agility: " << agi << std::endl;
		std::cout << "8: Luck: " << luc << std::endl;
		std::cin >> option;
		switch (option) {
		case 1 :
			if (str == 10) {
				std::cout << "Stat Limit is Ten" << std::endl;
			}
			else {
				str++;
				tempPoints--;
			}
			break;
		case 2:
			if (per == 10) {
				std::cout << "Stat Limit is Ten" << std::endl;
			}
			else {
				per++;
				tempPoints--;
			}
			break;
		case 3:
			if (ref == 10) {
				std::cout << "Stat Limit is Ten" << std::endl;
			}
			else {
				ref++;
				tempPoints--;
			}
			break;
		case 4:
			if (end == 10) {
				std::cout << "Stat Limit is Ten" << std::endl;
			}
			else {
				end++;
				tempPoints--;
			}
			break;
		case 5:
			if (cha == 10) {
				std::cout << "Stat Limit is Ten" << std::endl;
			}
			else {
				cha++;
				tempPoints--;
			}
			break;
		case 6:
			if (intel == 10) {
				std::cout << "Stat Limit is Ten" << std::endl;
			}
			else {
				intel++;
				tempPoints--;
			}
			break;
		case 7:
			if (agi == 10) {
				std::cout << "Stat Limit is Ten" << std::endl;
			}
			else {
				agi++;
				tempPoints--;
			}
			break;
		case 8:
			if (luc == 10) {
				std::cout << "Stat Limit is Ten" << std::endl;
			}
			else {
				luc++;
				tempPoints--;
			}
			break;
		}
		system("CLS");
	}
}

//changeCCSkills(): Allows User Input to Increase Three Human Player Skills by One
void changeCCSkills(Human& player) {
	int tempPoints = 3;
	int option;
	bool hasChosen1 = false;
	bool hasChosen2 = false;
	bool hasChosen3 = false;
	bool hasChosen4 = false;
	bool hasChosen5 = false;
	bool hasChosen6 = false;
	bool hasChosen7 = false;
	bool hasChosen8 = false;
	bool hasChosen9 = false;
	bool hasChosen10 = false;
	bool hasChosen11= false;
	bool hasChosen12 = false;
	bool hasChosen13 = false;
	bool hasChosen14 = false;
	bool hasChosen15 = false;
	bool hasChosen16 = false;
	bool hasChosen17 = false;
	bool hasChosen18 = false;
	bool hasChosen19 = false;
	bool hasChosen20 = false;
	while (tempPoints != 0) {
		std::cout << "Choose Three Skills to Increase" << std::endl;
		std::cout << "Remaining Skill Points Remaining: " << tempPoints << std::endl;
		std::cout << "1: Acrobatics: " << player.getAcrobatics() << std::endl;
		std::cout << "2: Acting: " << player.getActing() << std::endl;
		std::cout << "3: Arcane: " << player.getArcane() << std::endl;
		std::cout << "4: Athletics: " << player.getAthletics() << std::endl;
		std::cout << "5: Bargaining: " << player.getBargaining() << std::endl;
		std::cout << "6: Deception: " << player.getDeception() << std::endl;
		std::cout << "7: Heavy Weapons: " << player.getHeavyweapons() << std::endl;
		std::cout << "8: Light Weapons: " << player.getLightweapons() << std::endl;
		std::cout << "9: Lore: " << player.getLore() << std::endl;
		std::cout << "10: Intimidation: " << player.getIntimidation() << std::endl;
		std::cout << "11: Investigation: " << player.getInvestigation() << std::endl;
		std::cout << "12: Medicine: " << player.getMedicine() << std::endl;
		std::cout << "13: Medium Weapons: " << player.getMediumweapons() << std::endl;
		std::cout << "14: Pursuasion: " << player.getPursuasion() << std::endl;
		std::cout << "15: Ranged Bolt: " << player.getRangedbolt() << std::endl;
		std::cout << "16: Ranged Powder: " << player.getRangedpowder() << std::endl;
		std::cout << "17: Ranged String: " << player.getRangedstring() << std::endl;
		std::cout << "18: Stealth: " << player.getStealth() << std::endl;
		std::cout << "19: Survival: " << player.getSurvival() << std::endl;
		std::cout << "20: Thievery: " << player.getThievery() << std::endl;
		std::cout << "Input Skill Number:" << std::endl;
		std::cin >> option;
		switch (option) {
		case 1: 
			if (hasChosen1) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incAcrobatics();
				hasChosen1 = true;
				tempPoints--;
			}
			break;
		case 2:
			if (hasChosen2) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incActing();
				hasChosen2 = true;
				tempPoints--;
			}
			break;
		case 3:
			if (hasChosen3) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incArcane();
				hasChosen3 = true;
				tempPoints--;
			}
			break;
		case 4:
			if (hasChosen4) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incAthletics();
				hasChosen4 = true;
				tempPoints--;
			}
			break;
		case 5:
			if (hasChosen5) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incBargaining();
				hasChosen5 = true;
				tempPoints--;
			}
			break;
		case 6:
			if (hasChosen6) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incDeception();
				hasChosen6 = true;
				tempPoints--;
			}
			break;
		case 7:
			if (hasChosen7) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incHeavyweapons();
				hasChosen7 = true;
				tempPoints--;
			}
			break;
		case 8:
			if (hasChosen8) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incLightweapons();
				hasChosen8 = true;
				tempPoints--;
			}
			break;
		case 9:
			if (hasChosen9) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incLore();
				hasChosen9 = true;
				tempPoints--;
			}
			break;
		case 10:
			if (hasChosen10) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incIntimidation();
				hasChosen10 = true;
				tempPoints--;
			}
			break;
		case 11:
			if (hasChosen11) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incInvestigation();
				hasChosen11 = true;
				tempPoints--;
			}
			break;
		case 12:
			if (hasChosen12) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incMedicine();
				hasChosen12 = true;
				tempPoints--;
			}
			break;
		case 13:
			if (hasChosen13) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incMediumweapons();
				hasChosen13 = true;
				tempPoints--;
			}
			break;
		case 14:
			if (hasChosen14) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incPursuasion();
				hasChosen14 = true;
				tempPoints--;
			}
			break;
		case 15:
			if (hasChosen15) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incRangedbolt();
				hasChosen15 = true;
				tempPoints--;
			}
			break;
		case 16:
			if (hasChosen16) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incRangedpowder();
				hasChosen16 = true;
				tempPoints--;
			}
		case 17:
			if (hasChosen17) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incRangedstring();
				hasChosen17 = true;
				tempPoints--;
			}
			break;
		case 18:
			if (hasChosen18) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incStealth();
				hasChosen18 = true;
				tempPoints--;
			}
			break;
		case 19:
			if (hasChosen19) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incSurvival();
				hasChosen19 = true;
				tempPoints--;
			}
			break;
		case 20:
			if (hasChosen20) {
				std::cout << "Skill Already Increased." << std::endl;
			}
			else {
				player.incThievery();
				hasChosen20 = true;
				tempPoints--;
			}
			break;
		}
		system("CLS");
	}
}

//changeCCGear(): Equips the Human Player with a Weapon of the User's Choice
void changeCCGear(Human& player) {
	int optionWeapon;
	int gear = 1;
	while (gear != 0) {
		std::cout << "Would You Like A: " << std::endl;
		std::cout << "1: " << Weapons::Battleaxe.wepDescript() << std::endl;
		std::cout << "2: " << Weapons::Broadsword.wepDescript() << std::endl;
		std::cout << "3: " << Weapons::Assblade.wepDescript() << std::endl;
		std::cin >> optionWeapon;
		switch (optionWeapon) {
		case 1:
			player.equipWeapon(Weapons::Battleaxe);
			player.equipArmor(Armors::TravelCloak);
			gear--;
			break;
		case 2:
			player.equipWeapon(Weapons::Broadsword);
			player.equipArmor(Armors::TravelCloak);
			gear--;
			break;
		case 3:
			player.equipWeapon(Weapons::Assblade);
			player.equipArmor(Armors::TravelCloak);
			gear--;
			break;
		}
	}
	system("CLS");
}