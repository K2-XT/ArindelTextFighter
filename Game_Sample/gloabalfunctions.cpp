//globalfunctions.cpp: Contains implementation for the functions defined in globalfunctions.h
#include "mergesort.h"
#include "globalfunctions.h"
#include <queue>
#include <ctime>
#include <random>

//int statCheck(): Takes in One of the Character's Stats, then Rolls the Appropriate Amount of Dice.
int sCheck(int stat, std::queue<int>& curQueue) {
	int check;
	sRoll(stat, curQueue); 
	check = rollTotal(curQueue);
	return check;
}

//void statCheck(): Takes a Stat and Rolls the Stat's Amount of d10's, Fills a curRoll Queue with the Rolls.
void sRoll(int stat, std::queue<int>& curQueue) {
	int curDie = 0;
	int lastRoll;
	for (int i = 0; stat > i; i++) {
		lastRoll = rolld10();
		curQueue.push(lastRoll);
	}
}

//int checkTotal(): Takes the Current Rolls and Totals the Values.
int rollTotal(std::queue<int>& curQueue) {
	int total = 0;
	int size = curQueue.size();
	for (int i = 0; size >= i; i++) {
		total += curQueue.front();
		curQueue.pop();
	}
	return total;
}

//int intkintRoll: Allows For The Rolling of Two Values, Then Only Keeping the Second
int rollKeep(int first, int keep, std::queue<int>& curQueue) {
	sRoll(first, curQueue);
	sRoll(keep, curQueue);
	mergesort(curQueue);
	int size = keep;
	int total = 0;
	for (int i = 0; size > i && curQueue.size() > 0; i++) {
		total += curQueue.front();
		curQueue.pop();
	}
	return total;
}

//int rollDam(): Used for weapons. Rolls the weapon's Damage struct to generate a value to damage.
int rollDam(int first, int second, int& keep, std::queue<int>& curQueue) {
	sRoll(first, curQueue);
	sRoll(second, curQueue);
	mergesort(curQueue);
	int size = keep;
	int total = 0;
	for (int i = 0; size > i; i++) {
		total += curQueue.front();
		curQueue.pop();
	}
	return total;
}

//int rolld10(): Generates a number between 1 and 10.
int rolld10() {
	// shared random number generator (seeded with clock time)
	static std::default_random_engine randEngine(time(0));
	// shared uniform distribution
	static std::uniform_int_distribution<int> dist1To10(1, 10);
	// return a sample
	return dist1To10(randEngine);
}