#include "Character.h"
#include <iostream>

int main (const int argc, const char* argv[])
{
	if (argc == 3)
	{
		std::vector<std::string> characterAttributes = Character::parseUnit(argv[1]);
		Character player1 = Character(characterAttributes.at(0), stoul(characterAttributes.at(1)), stoul(characterAttributes.at(2)));
		characterAttributes = Character::parseUnit(argv[2]);
		Character player2 = Character(characterAttributes.at(0), stoul(characterAttributes.at(1)), stoul(characterAttributes.at(2)));

		bool firstsTurn = true;
		while (player1.getHP() > 0 && player2.getHP() > 0)
		{
			std::cout << player1.getName() << ": HP: " << player1.getHP() << ", DMG: " << player1.getDMG() << std::endl;
			std::cout << player2.getName() << ": HP: " << player2.getHP() << ", DMG: " << player2.getDMG() << std::endl;

			if (firstsTurn)
			{
				std::cout << player1.getName() << " -> " << player2.getName() << std::endl;
				player2.gotHit(player1.getDMG());
			}
			else
			{
				std::cout << player2.getName() << " -> " << player1.getName() << std::endl;
				player1.gotHit(player2.getDMG());
			}
			firstsTurn = !firstsTurn;
		}

		std::cout << player1.getName() << ": HP: " << player1.getHP() << ", DMG: " << player1.getDMG() << std::endl;
		std::cout << player2.getName() << ": HP: " << player2.getHP() << ", DMG: " << player2.getDMG() << std::endl;

		if (player1.getHP() == 0)
		{
			std::cout << player2.getName() << " wins. Remaining HP: " << player2.getHP() << std::endl;
		}
		else
		{
			std::cout << player1.getName() << " wins. Remaining HP: " << player1.getHP() << std::endl;
		}
	}
	else
	{
		//later to be adjusted !!!!!!!!!!!!!
		throw std::runtime_error("Incorrect number of arguments!");
	}
    return 0;
}