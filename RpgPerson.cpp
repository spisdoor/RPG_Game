#include "RpgPerson.h"

RpgPerson::RpgPerson(std::string name1, int level1, std::string job1, int maxHp1, int strength1, int defence1, int x1, int y1, int crits1, int coins1, int experience1, int currentHp1): RpgCreature(name1, maxHp1, strength1, defence1, crits1, coins1, experience1, currentHp1) {
	x = x1;
	y = y1;
	level = level1;
	job = job1;
}
void RpgPerson::useSkill(int i, RpgCreature& enemy, RpgCreature& person, int level) {}
void RpgPerson::printSkill() {}

int RpgPerson::getLevel() {
	return level;
}
int RpgPerson::getX() {
	return x;
}
int RpgPerson::getY() {
	return y;
}
void RpgPerson::setPosition(int x1, int y1) {
	x = x1;
	y = y1;
}
void RpgPerson::moveUp() {
	y--;
}
void RpgPerson::moveDown() {
	y++;
}
void RpgPerson::moveLeft() {
	x--;
}
void RpgPerson::moveRight() {
	x++;
}
void RpgPerson::minusExperience(int value) {
	if (experience < value)
		experience = 0;
	else
		experience -= value;
}
void RpgPerson::raiseExperience(int value) {
	experience += value;
}
bool RpgPerson::checkLevelUp() {
	if (experience >= (int)(7 * (0.5 + (float)((float)level / 2))))
		return true;
	else
		return false;
}
void RpgPerson::levelUp() {
	experience -= (int)(7 * (0.5 + (float)((float)level / 2)));
	level++;
	std::cout << "Level up!!! You are level " << level << " ." << std::endl;
}
void RpgPerson::statusUp() {
	maxHp += 5;
	strength++;
	defence++;
}
void RpgPerson::printStatus() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Lv: " << level << std::endl;
	std::cout << "Hp: " << getCurrentHp() << std::endl;
	std::cout << "Strength: " << strength << std::endl;
	std::cout << "Defence: " << defence << std::endl;
	std::cout << "Exp: " << experience << "/" << (int)(7 * (0.5 + (float)((float)level / 2))) << std::endl;
}
