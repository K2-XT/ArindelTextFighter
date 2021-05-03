//arindel_tests.cpp: Contains test drivers for the whole program. Runs first and foremost when called from mainGame.cpp.
#include <iostream>
#include <cassert>
#include "globalfunctions.h"
#include "mergesort.h"
#include "human.h"
#include "weaponsandarmor.h"

//Function Prototypes
void testMergeInt();
void testMergeString();
void testHuman(Human&);
void testHumanSkillLevel(Human&);
void testEquipment(Human&);
void testHealth(Human&);


//secondaryMain(): Test Driver
int secondaryMain() {
	std::cout << "Commencing Pre-Processing Tests..." << std::endl;
	Human Dallin("DALLIN", 9, 4, 5, 6, 3, 4, 9, 10);
	testMergeInt();
	testMergeString();
	testHuman(Dallin);
	testHumanSkillLevel(Dallin);
	testEquipment(Dallin);
	testHealth(Dallin);
	std::cout << "Tests Passed." << std::endl;
	return 0;
}

//void testMergeInt(): Tests a Queue of Ints
void testMergeInt() {
	//Creates scrambled queue...
	std::cout << "Testing testMergeInt...";
	std::queue<int> iqueue;
	iqueue.push(1);
	iqueue.push(2);
	iqueue.push(6);
	iqueue.push(4);
	iqueue.push(5);
	iqueue.push(8);
	iqueue.push(7);
	iqueue.push(3);
	//Sorts...
	mergesort(iqueue);
	std::queue<int> expected;
	expected.push(8);
	expected.push(7);
	expected.push(6);
	expected.push(5);
	expected.push(4);
	expected.push(3);
	expected.push(2);
	expected.push(1);
	//Compares sorted queue the the expected queue.
	while (!iqueue.empty()) {
		assert(expected.front() == iqueue.front());
		iqueue.pop();
		expected.pop();
	}
	std::cout << "Passed." << std::endl;
}

//void testMergeString(): Tests a Queue of Strings
void testMergeString() {
	//Creates a scrambled queue...
	std::cout << "Testing testMergeString()...";
	std::queue<std::string> squeue;
	squeue.push("alpha");
	squeue.push("india");
	squeue.push("bravo");
	squeue.push("hotel");
	squeue.push("delta");
	squeue.push("charlie");
	squeue.push("echo");
	squeue.push("golf");
	squeue.push("foxtrot");
	//Sorts...
	mergesort(squeue);
	std::queue<std::string> expected;
	expected.push("india");
	expected.push("hotel");
	expected.push("golf");
	expected.push("foxtrot");
	expected.push("echo");
	expected.push("delta");
	expected.push("charlie");
	expected.push("bravo");
	expected.push("alpha");
	//Compares scrambled queue to expected queue.
	while (!squeue.empty()) {
		assert(expected.front() == squeue.front());
		squeue.pop();
		expected.pop();
	}
	std::cout << "Passed." << std::endl;
}

//testHuman(): Creates a Human and sets their stats. Then checks to make sure the stats set correctly.
void testHuman(Human &Dallin) {
	std::cout << "Testing Human Creation...";
	assert(Dallin.getStr() == 9);
	assert(Dallin.getPer() == 4);
	assert(Dallin.getRef() == 5);
	assert(Dallin.getEnd() == 6);
	assert(Dallin.getChar() == 3);
	assert(Dallin.getIntel() == 4);
	assert(Dallin.getAgi() == 9);
	assert(Dallin.getLuck() == 10);
	std::cout << "Passed." << std::endl;
}

//testHumanSkillLevel(): Levels up one Human skill and checks to see if the value has been increased by one.
void testHumanSkillLevel(Human &Dallin) {
	std::cout << "Testing Human Skill Incrementation...";
	assert(Dallin.getAthletics() == 8);
	Dallin.incAthletics();
	assert(Dallin.getAthletics() == 9);
	assert(Dallin.getInvestigation() == 3);
	Dallin.incInvestigation();
	assert(Dallin.getInvestigation() == 4);
	assert(Dallin.getThievery() == 4);
	Dallin.incThievery();
	assert(Dallin.getThievery() == 5);
	std::cout << "Passed." << std::endl;
}

//testEquipment(): Equips a Human, tests if equipment is actually held.
void testEquipment(Human &Dallin) {
	std::cout << "Testing Equipment...";
	Dallin.equipWeapon(Weapons::Battleaxe);
	assert(Dallin.getWeaponName() == "Battleaxe");
	Dallin.equipArmor(Armors::TravelCloak);
	assert(Dallin.getArmorName() == "Traveler's Cloak");
	std::cout << "Passed." << std::endl;
}

//testHealth(): Completely runs through the condition system and tests each health state and the TNinc associated.
void testHealth(Human &Dallin) {
	std::cout << "Testing Health System..." << std::endl;
	assert(Dallin.getHealth() == 120);
	Dallin.dynamHealth(15);
	assert(Dallin.condition() == 3);
	Dallin.dynamHealth(15);
	assert(Dallin.condition() == 5);
	Dallin.dynamHealth(15);
	assert(Dallin.condition() == 10);
	Dallin.dynamHealth(15);
	assert(Dallin.condition() == 20);
	Dallin.dynamHealth(15);
	assert(Dallin.condition() == 40);
	Dallin.dynamHealth(15);
	assert(Dallin.condition() == 50);
	std::cout << "Passed." << std::endl;
}