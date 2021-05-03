//combatround.cpp: Contains implemntation of functions based on creating combat rounds pitting a user against AI.
#include "combatround.h"
#include <iostream>
#include <Windows.h>

//void combatMain(): Takes in two humans and pits them against each other.
void combatMain(Human &lhs, Human &rhs) {
	bool playerTurn;
	std::cout << "Combat has started." << std::endl;
	std::cout << "Both parties are rolling intiative..." << std::endl;
	//Roll Initiative...
	compInitiative(lhs, rhs, playerTurn);
	if (playerTurn == true) { std::cout << lhs.getName() << " GOES FIRST!" << std::endl; }
	else { std::cout << rhs.getName() << " GOES FIRST!" << std::endl; }
	system("pause");
	system("CLS");
	//While both Humans are alive...
	while (lhs.getHealth() > 0 && rhs.getHealth() > 0) {
		//Roll Attack and Damage
		int attack = lhs.rollAttack(lhs) - lhs.condition();
		int damage = lhs.rollDamage(lhs);
		int aiAttack = rhs.rollAttack(rhs) - rhs.condition();
		//Just in case the player does nothing but defend, the AI will hit every four loops.
		int counter = 0;
		counter++;
		if (counter > 4) {
			aiAttack = 1000;
			counter = 0;
		}
		int aiDamage = rhs.rollDamage(rhs);
		//If it is the player's turn...
		if (playerTurn == true) {
			system("CLS");
			//Display Player Health and Options...
			std::cout << lhs.getName() << " Health: " << lhs.getHealth() << std::endl;
			std::cout << lhs.getName() << "'s turn" << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			int option;
			std::cin >> option;
			switch (option) {
				//If attacking...
			case 1:
				//Compare the user's attack to the AI's defense. If it is higher...
				if (attack >= rhs.getDefense()) {
					std::cout << lhs.getName() << " attacks!" << std::endl;
					//Take the user's damage roll and subtract it from the AI's Health.
					rhs.dynamHealth(damage);
					//If the AI is dead...
					if (rhs.getHealth() < 0) {
						//Turn the playerTurn to true so the AI doesn't get another turn while dead.
						playerTurn = true;
						system("pause");
						system("CLS");
						//Break.
						break;
					}
					//If not, give the AI a turn.
					playerTurn = false;
					system("pause");
					system("CLS");
					break;
				}
				//If the player cannot match the AI's defense, they miss.
				else {
					system("CLS");
					std::cout << "You missed." << std::endl;
					system("pause");
					playerTurn = false;
					break;
				}
				//If the player defends...
			case 2:
				system("CLS");
				std::cout << lhs.getName() << " defends!" << std::endl;
				Sleep(300);
				std::cout << rhs.getName() << "'s turn" << std::endl;
				Sleep(300);
				//Let the AI have a turn, but increase defense by 5.
				if (aiAttack >= (lhs.getDefense() + 5)) {
					//Decrease health if hit.
					lhs.dynamHealth(aiDamage);
					//Back to the player's turn.
					playerTurn = true;
					break;
				}
				//If missed, player blocks the attack.
				else {
				std::cout << lhs.getName() << " blocked the attack!" << std::endl;
				system("pause");
				break;
				}
			}
		}
		//AI Turn
		if (playerTurn == false) {
			std::cout << rhs.getName() << "'s turn" << std::endl;
			Sleep(1000);
			//If AI hits player...
			if (aiAttack >= lhs.getDefense()) {
				std::cout << rhs.getName() << " attacks!" << std::endl;
				//Subtract Health.
				lhs.dynamHealth(aiDamage);
				system("pause");
				playerTurn = true;
			}
			//AI misses.
			else {
				std::cout << rhs.getName() << " missed." << std::endl;
				system("pause");
				playerTurn = true;
			}
		}
	}
	//If AI has died...
	if (rhs.getHealth() <= 0) {
		std::cout << rhs.getName() << " WAS SLAIN." << std::endl;
		system("pause");
		Sleep(300);
	}
	//If player has died...
	else {
		std::cout << lhs.getName() << " WAS SLAIN." << std::endl;
		system("pause");
		Sleep(300);
		exit(0);
	}
}

//void compInitiative(): Takes in two Humans and a bool. Both Humans roll initiative, whoever wins determines the bool setting the user vs. the ai turn.
void compInitiative(Human &lhs, Human &rhs, bool &playerTurn) {
	int lhsInitiative = lhs.rollInitiative();
	int rhsInitiative = rhs.rollInitiative();
	std::cout << lhs.getName() << " rolled " << lhsInitiative << "." << std::endl;
	std::cout << rhs.getName() << " rolled " << rhsInitiative << "." << std::endl << std::endl;
	if (lhsInitiative > rhsInitiative) {
		playerTurn = true;
	}
	else if (rhsInitiative > lhsInitiative) {
		playerTurn = false;
	}
	else {
		compInitiative(lhs, rhs, playerTurn);
	}
}