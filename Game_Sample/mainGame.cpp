//Arindel by Andy Orton and Payton Pehrson, made November of 2018
#include <stdlib.h>
#include "human.h"
#include "mergesort.h"
#include "weapon.h"
#include "armor.h"
#include "globalfunctions.h"
#include "charcreate.h"
#include "weaponsandarmor.h"
#include "combatround.h"
#include <Windows.h>

//Function Prototypes
void towerFightsMain(Human&);
void towerFights(Human&, Human&);

//int main(): Main Driver
int main() {
	//Calling of the Test Driver
	secondaryMain();
	system("CLS");
	std::cout << "Welcome to Arindel. Please Create Your Fighter..." << std::endl;
	system("pause");
	Human player = CCMain();
	towerFightsMain(player);
	system("pause");
	return 0;
}

//void towerFightsMain(): Takes in player character and pits them against multiple AI.
void towerFightsMain(Human &player) {
	std::cout << "WELCOME WARRIOR TO THE TOWER OF HANOI" << std::endl;

	Human Adam("Adam", 3, 3, 3, 3, 3, 3, 3, 3);
	Adam.equipWeapon(Weapons::Assblade);
	Adam.equipArmor(Armors::TravelCloak);
	std::cout << "YOUR FIRST CHALLENGE WILL BE ADAM, TERROR OF THE BINARY FOREST!" << std::endl;
	towerFights(player, Adam);

	Human Warner("Warner", 4, 4, 4, 4, 4, 4, 4, 4);
	Warner.equipWeapon(Weapons::Broadsword);
	Warner.equipArmor(Armors::TravelCloak);
	std::cout << "YOUR SECOND CHALLENGE WILL BE WARNER THE CATCHER!" << std::endl;
	towerFights(player, Warner);

	Human Hunter("Hunter", 5, 5, 5, 5, 5, 5, 5, 5);
	Hunter.equipWeapon(Weapons::Broadsword);
	Hunter.equipArmor(Armors::TravelCloak);
	std::cout << "YOUR THIRD CHALLENGE WILL BE HUNTER THE STRANGE!" << std::endl;
	towerFights(player, Hunter);

	Human Dallin("Dallin", 9, 4, 5, 6, 3, 4, 9, 10);
	Dallin.equipWeapon(Weapons::Broadsword);
	Dallin.equipArmor(Armors::TravelCloak);
	std::cout << "YOUR FOURTH CHALLENGE WILL BE DALLIN, THAT ONE KID NOBODY REALLY KNEW BUT WAS COOL ANYWAY!" << std::endl;
	towerFights(player, Dallin);

	Human Josh("Joshua Barney", 10, 10, 10, 10, 10, 10, 10, 10);
	Josh.equipWeapon(Weapons::Battleaxe);
	Josh.equipArmor(Armors::TravelCloak);
	std::cout << "YOUR FINAL CHALLENGE WILL BE JOSHUA BARNEY, YOU'RE NOT GOING TO WIN!" << std::endl;
	towerFights(player, Josh);

}

//void towerFights(): Takes AI and player, begins combatrounds.
void towerFights(Human &player, Human &AI) {
	std::cout << "THE FIGHT WILL COMMENCE IN " << std::endl;
	Sleep(1500);
	std::cout << "3\n";
	Sleep(1500);
	std::cout << "2\n";
	Sleep(1500);
	std::cout << "1\n";
	std::cout << "THE FIGHT HAS COMMENCED!" << std::endl;
	Sleep(4000);
	system("CLS");
	combatMain(player, AI);
}