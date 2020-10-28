#include "Character.h"

void ruleOutNegativeAnyFloat(std::any& num)
{
	if (std::any_cast<float>(num) < 0)
	{
		throw std::runtime_error("Negative numeric value is not acceptable here!");
	}
}

Character::Character(const std::string characterName, float healthPoints, float damagePoints, float attackSpeed)
	: name(characterName)
{
	HP = maxHP = healthPoints;
	DMG = damagePoints;
	AS = attackSpeed;
}

const std::string Character::getName() const
{
	return name;
}

const float Character::getHealthPoints() const
{
	return HP;
}

const float Character::getDMG() const
{
	return DMG;
}

const float Character::getAS() const
{
	return AS;
}

float Character::gotHit(Character* attacker)
{
	float potentialXP = attacker->getDMG();
	if (HP - potentialXP > 0)
	{
		HP -= potentialXP;
		return potentialXP;
	}
	else
	{
		potentialXP = HP;
		HP = 0;
		return potentialXP;
	}
}

void Character::doHit(Character& victim)
{
	victim.gotHit(this);
}

bool Character::isAlive()
{
	return HP > 0;
}

void Character::fightTilDeath(Character enemy)
{
	float ASTimer1 = 0, ASTimer2 = 0;

	while (enemy.getHealthPoints() > 0 && HP > 0)
	{
		if (ASTimer1 <= ASTimer2)
		{
			enemy.doHit(*this);
			ASTimer1 += enemy.getAS();
		}
		else
		{
			this->doHit(enemy);
			ASTimer2 += AS;
		}
	}
}
