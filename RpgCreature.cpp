#include "RpgCreature.h"

RpgCreature::RpgCreature() {}
RpgCreature::RpgCreature(std::string name) {}
RpgCreature::RpgCreature(std::string name1, int maxHp1, int strength1, int defence1, int crits1, int coins1, int experience1, int currentHp1): name(name1), maxHp(maxHp1), strength(strength1), defence(defence1), crits(crits1), coins(coins1), experience(experience1), currentHp(currentHp1) {
}

std::string RpgCreature::getName() {
	return name;
}
int RpgCreature::getCoins() {
	return coins;
}
int RpgCreature::getCrits() {
	return crits;
}
int RpgCreature::getMaxHp() {
	return maxHp;
}
int RpgCreature::getCurrentHp() {
	return currentHp;
}
int RpgCreature::getStrength() {
	return strength;
}
int RpgCreature::getDefence() {
	return defence;
}
void RpgCreature::useCoins() {
	this->coins -= 5;
}
void RpgCreature::addCoins(int c) {
	this->coins += c;
}
int RpgCreature::getExperience() {
	return this->experience;
}
bool RpgCreature::isDead() {
	if (currentHp <= 0)
		return true;
	else
		return false;
}
void RpgCreature::loseHp(int value) {
	this->currentHp -= value;
	if (this->currentHp < 0)
		this->currentHp = 0;
}
void RpgCreature::recoverHp() {
	this->currentHp = this->getMaxHp();
}
void RpgCreature::attack(RpgCreature& enemy) {
	int v = this->strength - enemy.defence;
	if (enemy.defence >= this->strength) {
		v = 1;
	}
	int randomPorN = 0;
	int randomAttack = 0;
	randomAttack += rand() % 3 + 1;
	randomPorN += rand() % 3 + 1;
	if (randomPorN == 1) {
		v -= randomAttack;
	}
	else if (randomPorN == 2) {
		v += randomAttack;
	}
	else {}
	int critsAttack = 0;
	critsAttack += rand() % getCrits() + 1;
	if (critsAttack <= getCrits()) {
		v = v * 2;
	}
	if (v <= 0) {
		v = 1;
	}
	if (enemy.getCurrentHp() - v >= 0) {
		enemy.loseHp(v);
		std::cout << this->getName() << " attacked " << enemy.getName() << ", caused " << v << " damages!" << enemy.getName() << "'s hp: " << enemy.getCurrentHp() << std::endl;
	}
	else {
		std::cout << this->getName() << " attacked " << enemy.getName() << ", caused " << enemy.getCurrentHp() << " damages!";
		enemy.loseHp(enemy.getCurrentHp());
		std::cout << enemy.getName() << "'s hp: " << enemy.getCurrentHp() << std::endl;
	}
}
