#ifndef RPGPERSON_H_INCLUDED
#define RPGPERSON_H_INCLUDED

#include <vector>
#include "RpgCreature.h"

class RpgPerson: public RpgCreature {
	public:
		RpgPerson(std::string name, int level1, std::string job1, int maxHp, int strength, int defence, int x, int y, int crits, int coins, int experience, int currentHp);
		int getX();
		int getY();
		void setPosition(int x, int y);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void minusExperience(int value);
		void raiseExperience(int value);
		bool checkLevelUp();
		void levelUp();
		virtual void statusUp();
		virtual void printStatus();
		int getLevel();
		virtual void useSkill(int i, RpgCreature& enemy, RpgCreature& person, int level);
		virtual void printSkill();

		std::string job;
	protected:
		int level;
	private:
		int x;
		int y;
};

#endif // RPGPERSON_H_INCLUDED
