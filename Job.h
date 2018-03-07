#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "RpgPerson.h"
#include "RpgCreature.h"

class save: public RpgPerson {

	public:
		std::string map1;
		save(std::string name1, int level1, std::string job1, int currentHp1, int maxHp1, int strength1, int defence1, int crits1, int coins, int experience1, std::string map1, int mapX1, int mapY1);

		std::string getMapName() {
			return map1;
		}
		void print() {
			std::cout << "Name: " << this->getName() << std::endl;
			std::cout << "Jobs: " << this->job << std::endl;
			std::cout << "Level: " << this->getLevel() << std::endl;
		}
};
class swordMan: public RpgPerson {
	private:
		std::vector<std::string> skill;
	public:
		swordMan(std::string name, int level1, int maxHp, int strength, int defence, int x, int y, int crits, int coins, int experience, int currentHp);
		virtual void statusUp();
		virtual void printStatus();
		virtual void useSkill(int i, RpgCreature& enemy, RpgCreature& person, int level);
		virtual void printSkill();
};

class Thief: public RpgPerson {
	private:
		std::vector<std::string> skill;
	public:
		Thief(std::string name, int level1, int maxHp, int strength, int defence, int x, int y, int crits, int coins, int experience, int currentHp);
		virtual void statusUp();
		virtual void printStatus();
		virtual void useSkill(int i, RpgCreature& enemy, RpgCreature& person, int level);
		virtual void printSkill();
};

class Magicion: public RpgPerson {
	private:
		std::vector<std::string> skill;
	public:
		Magicion(std::string name, int level1, int maxHp, int strength, int defence, int x, int y, int crits, int coins, int experienxe, int currentHp);
		virtual void statusUp();
		virtual void printStatus();
		virtual void useSkill(int i, RpgCreature& enemy, RpgCreature& person, int level);
		virtual void printSkill();
};

#endif // JOB_H_INCLUDED
