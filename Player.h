#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <math.h>

class Hero : public Character
{
private:
	float XP;
	Hero(const std::string characterName, float healthPoints, float damagePoints, float attackSpeed);
	void levelup(float levelupXP);
	void gainXP(float damagePoints);
public:
	static Hero parse(std::string fileName);
	void doHit(Character& victim);
	/**
	 @return the Hero's current level.
	 */
	const unsigned int getLevel() const;
};

#endif
