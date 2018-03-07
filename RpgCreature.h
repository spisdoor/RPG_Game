#ifndef RPGCREATURE_H_INCLUDED
#define RPGCREATURE_H_INCLUDED

#include <iostream>
#include <time.h>
#include <stdlib.h>

class RpgCreature {
	public:
		RpgCreature();
		RpgCreature(std::string name);
		RpgCreature(std::string name, int maxHp, int strength, int defencence, int crits, int coins, int experience, int currentHp);
		std::string getName();
		int getCoins();
		int getCrits();
		int getMaxHp();
		int getCurrentHp();
		int getStrength();
		int getDefence();
		void useCoins();
		int getExperience();
		bool isDead();
		void loseHp(int value);
		void recoverHp();
		void attack(RpgCreature& enemy);
		void addCoins(int c);
	protected:
		std::string name;
		int maxHp;
		int currentHp;
		int strength;
		int defence;
		int crits;
		int coins;
		int experience;
};

#endif // RPGCREATURE_H_INCLUDED
