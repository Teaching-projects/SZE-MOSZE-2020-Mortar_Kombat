/**
 * @class Character
 *
 * @brief This class is the spine of our game, links together the varaiable parts.
 *
 * @author Mortar_Kombat
 *
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "JSONParser.h"

#include <string>
#include <fstream>
#include <map>
#include <any>

class Character
{
protected:
	const std::string name;
	float maxHP, HP, DMG, AS;
	Character(const std::string characterName, float healthPoints, float damagePoints, float attackSpeed);
	const float getDMG() const;
	const float getAS() const;
	virtual void doHit(Character& victim);
public:
	/**
	 *
	 *@return Character's name
	 */
	const std::string getName() const;
	/**
	 *@return Character's Health Points
	 */
	const float getHealthPoints() const;
	/**
	 *Calculates the potentialXP from the damage dealt.
	 *@param The function's argument is the attacker's pointer.
	 *@return Returns the poteintalXP.
	 */
	float gotHit(Character* attacker);
	bool isAlive();
	void fightTilDeath(Character enemy);
};

void ruleOutNegativeAnyFloat(std::any& num);

#endif
