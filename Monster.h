#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "RpgCreature.h"

class Monster: public RpgCreature {
	public:
		Monster(std::string name, int maxHp, int strength, int defence, int crits, int coins, int experience, int currentHp);
	private:
};

#endif // MONSTER_H_INCLUDED
