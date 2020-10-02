#include "Player.h"

Player::Player(const std::string characterName, const float healthPoints, const float damagePoints, const float experiencePoints) : Character(characterName, healthPoints, experiencePoints)
{
	XP = experiencePoints;
}

void Player::levelup(float levelupXP)
{
	while (levelupXP >= 100)
	{
		levelupXP -= 100;
		maxHP = round(HP * 1.1);
		DMG *= 1.1;
		HP = maxHP;
	}
}

void Player::gainXP(float damagePoints)
{
	levelup(XP - int(XP / 100) * 100 + damagePoints);
	XP += damagePoints;
}
