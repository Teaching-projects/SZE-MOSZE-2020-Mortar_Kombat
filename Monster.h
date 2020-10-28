#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

class Monster : public Character
{
public:
	Monster(const std::string characterName, float healthPoints, float damagePoints, float attackSpeed);
	static Monster parse(std::string fileName);
};

#endif
