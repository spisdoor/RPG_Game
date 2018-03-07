#include "Job.h"
save::save(std::string name1, int level1, std::string job1, int currentHp1, int maxHp1, int strength1, int defence1, int crits1, int coins, int experience1, std::string map1, int mapX1, int mapY1): RpgPerson(name1, level1, job1, maxHp1, strength1, defence1, mapX1, mapY1, crits1, coins, experience1, currentHp1) {
	this->map1 = map1;
}
swordMan::swordMan(std::string name, int level1, int maxHp, int strength, int defence, int x, int y ,int crits, int coins, int experience, int currentHp): RpgPerson(name, level1, "swordMan", maxHp, strength, defence, x, y, crits, coins, experience, currentHp) {
	skill.push_back("special attack");
	skill.push_back("recover");
	skill.push_back("blood");
}
void swordMan::printSkill() {
	for (int i = 0; i < skill.size(); i++) {
		std::cout << i+1 << ": " << skill[i] << std::endl;
	}
}
void swordMan::useSkill(int i, RpgCreature& enemy, RpgCreature& person, int level) {
	int t = 0;
	while (t == 0) {
		t = 1;
		switch(i) {
			case 1:
				{
					int num = (getLevel() + getStrength() + 2) * 2;
					enemy.loseHp(num);
					std::cout << "<Attack!!> You attacked " << enemy.getName() << " by " << num << " hp" << std::endl;
					std::cout << enemy.getName() << "'s hp: " << enemy.getCurrentHp() << std::endl;
					break;
				}
			case 2:
				{
					if (level < 2) {
						std::cout << "Can't use this skill! Your Level is too low!" << std::endl;
						std::cin >> i;
						t = 0;
						break;
					}
					int num = (getLevel() + 10) * 3;
					if (currentHp + num <= getMaxHp()) {
						currentHp += num;
						std::cout << "<Healing!!> You got " << num << " hp" << std::endl;
						std::cout << name << "'s hp: " << getCurrentHp() << std::endl;
					}
					else {
						num = getMaxHp() - currentHp;
						currentHp = getMaxHp();
						std::cout << "<Healing!!> You got " << num << " hp" << std::endl;
						std::cout << name << "'s hp: " << getCurrentHp() << std::endl;
					}
					break;
				}
			case 3:
				{
					if (level < 3) {
						std::cout << "Can't use this skill! Your Level is too low!" << std::endl;
						std::cin >> i;
						t = 0;
						break;
					}
					int num = enemy.getCurrentHp() / 2;
					currentHp += num;
					if (currentHp > maxHp) {
						currentHp = maxHp;
					}
					enemy.loseHp(num);
					std::cout << "<You blood slime!!> You got " << num << " hp from slime" << std::endl;
					std::cout << name << "'s hp: " << getCurrentHp() << std::endl;
					std::cout << enemy.getName() << "'s hp: " << enemy.getCurrentHp() << std::endl;
					break;
				}
			default:
				break;
		}
	}
}
void swordMan::statusUp() {
	maxHp += 5;
	strength += 1;
	defence += 2;
	crits += 0;
}
void swordMan::printStatus() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Lv: "<< level << std::endl;
	std::cout << "Job: swordMan"<< std::endl;
	std::cout << "Hp: "<< getCurrentHp() << "/" << getMaxHp() << std::endl;
	std::cout << "Strength: "<< strength << std::endl;
	std::cout << "Defence: "<< defence << std::endl;
	std::cout << "Crits: "<< crits << std::endl;
	std::cout << "Coins: "<< getCoins() << std::endl;
	std::cout << "Exp: "<< getExperience() << "/" << (int)(7 * (0.5 + (float)((float)level / 2))) << std::endl;
}	
Thief::Thief(std::string name, int level1, int maxHp, int strength, int defence, int x, int y, int crits, int coins, int experience, int currentHp): RpgPerson(name, level1, "Thief", maxHp, strength, defence, x, y, crits, coins, experience, currentHp) {
	skill.push_back("special attack");
	skill.push_back("recover");
	skill.push_back("blood");
}
void Thief::printSkill() {
	for (int i = 0; i < skill.size(); i++) {
		std::cout << i+1 << ": " << skill[i] << std::endl;
	}
}
void Thief::useSkill(int i, RpgCreature& enemy, RpgCreature& person, int level) {
	int t = 0;
	while (t == 0) {
		t = 1;
		switch(i) {
			case 1:
				{
					int num = (getLevel() + getStrength() + 3) * 2;
					enemy.loseHp(num);
					std::cout << "<Attack!!> You attacked " << enemy.getName() << " by " << num << " hp" << std::endl;
					std::cout << enemy.getName() << "'s hp: " << enemy.getCurrentHp() << std::endl;
					break;
				}
			case 2:
				{
					if (level < 2) {
						std::cout << "Can't use this skill! Your Level is too low!" << std::endl;
						std::cin >> i;
						t = 0;
						break;
					}
					int num = (getLevel() + 10) * 2;
					if (currentHp + num <= getMaxHp()) {
						currentHp += num;
						std::cout << "<Healing!!> You got " << num << " hp" << std::endl;
						std::cout << name << "'s hp: " << getCurrentHp() << std::endl;
					}
					else {
						num = getMaxHp() - currentHp;
						currentHp = getMaxHp();
						std::cout << "<Healing!!> You got " << num << " hp" << std::endl;
						std::cout << name << "'s hp: " << getCurrentHp() << std::endl;
					}
					break;
				}
			case 3:
				{
					if (level < 3) {
						std::cout << "Can't use this skill! Your Level is too low!" << std::endl;
						std::cin >> i;
						t = 0;
						break;
					}
					int num = person.getCrits();
					enemy.loseHp(num);
					std::cout << "<Crits Attack two times!!>" << std::endl;
					for (int j = 0; j < 2; j++) {
						std::cout << "You attacked " << enemy.getName() << " by " << num << " hp" << std::endl;
					}
					std::cout << enemy.getName() << "'s hp: " << enemy.getCurrentHp() << std::endl;
					break;
				}
			default:
				break;
		}
	}
}
void Thief::statusUp() {
	maxHp += 5;
	strength += 1;
	defence += 1;
	crits += 5;
}
void Thief::printStatus() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Lv: "<< level << std::endl;
	std::cout << "Job: Thief"<< std::endl;
	std::cout << "Hp: "<< getCurrentHp() << "/" << getMaxHp() << std::endl;
	std::cout << "Strength: "<< strength << std::endl;
	std::cout << "Defence: "<< defence << std::endl;
	std::cout << "Crits: "<< crits << std::endl;
	std::cout << "Coins: "<< getCoins() << std::endl;
	std::cout << "Exp: "<< getExperience() << "/" << (int)(7 * (0.5 + (float)((float)level / 2))) << std::endl;
}
Magicion::Magicion(std::string name, int level1, int maxHp, int strength, int defence, int x, int y, int crits, int coins, int experience, int currentHp): RpgPerson(name, level1, "Magicion", maxHp, strength, defence, x, y, crits, coins, experience, currentHp) {
	skill.push_back("special attack");
	skill.push_back("recover");
	skill.push_back("attack itself");
}
void Magicion::printSkill() {
	for (int i = 0; i < skill.size(); i++) {
		std::cout << i+1 << ": " << skill[i] << std::endl;
	}
}
void Magicion::useSkill(int i, RpgCreature& enemy, RpgCreature& person, int level) {
	int t = 0;
	while (t == 0) {
		t = 1;
		switch(i) {
			case 1:
				{
					int num = (getLevel() + getStrength() + 3) * 2;
					std::cout << "<Attack three times!!>" << std::endl;
					for (int j = 0; j < 3; j++) {
						enemy.loseHp(num);
						std::cout << "You attacked slime by " << num << " hp" << std::endl;
					}
					std::cout << enemy.getName() << "'s hp: " << enemy.getCurrentHp() << std::endl;
					break;
				}
			case 2:
				{
					if (level < 2) {
						std::cout << "Can't use this skill! Your Level is too low!" << std::endl;
						std::cin >> i;
						t = 0;
						break;
					}
					int num = (getLevel() + 5) * 2;
					if (currentHp + num <= getMaxHp()) {
						currentHp += num;
						std::cout << "<Healing!!> You got " << num << " hp" << std::endl;
						std::cout << name << "'s hp: " << getCurrentHp() << std::endl;
					}
					else {
						num = getMaxHp() - currentHp;
						currentHp = getMaxHp();
						std::cout << "<Healing!!> You got " << num << " hp" << std::endl;
						std::cout << name << "'s hp: " << getCurrentHp() << std::endl;
					}
					break;
				}
			case 3:
				{
					if (level < 3) {
						std::cout << "Can't use this skill! Your Level is too low!" << std::endl;
						std::cin >> i;
						t = 0;
						break;
					}
					std::cout << "<Make Slime attack itself!!>" << std::endl;
					int num = (enemy.getStrength() + getLevel()) * 2;
					enemy.loseHp(num);
					std::cout << enemy.getName() << " attack itself by " << num << " hp!!" << std::endl;
					std::cout << enemy.getName() << "'s hp: " << enemy.getCurrentHp() << std::endl;
					break;
				}
			default:
				break;
		}
	}
}
void Magicion::statusUp() {
	maxHp += 5;
	strength += 2;
	defence += 1;
	crits += 0;
}
void Magicion::printStatus() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Lv: "<< level << std::endl;
	std::cout << "Job: Magicion" << std::endl;
	std::cout << "Hp: "<< getCurrentHp() << "/" << getMaxHp() << std::endl;
	std::cout << "Strength: "<< strength << std::endl;
	std::cout << "Defence: "<< defence << std::endl;
	std::cout << "Crits: "<< crits << std::endl;
	std::cout << "Coins: "<< getCoins() << std::endl;
	std::cout << "Exp: "<< getExperience() << "/" << (int)(7 * (0.5 + (float)((float)level / 2))) << std::endl;
}
