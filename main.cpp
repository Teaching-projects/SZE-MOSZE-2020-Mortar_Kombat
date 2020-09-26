#include "Character.h"
#include <iostream>

int main (const int argc, const char* argv[])
{
	if (argc == 3)
	{
		Character player1 = Character::parseUnit(argv[1]);
		Character player2 = Character::parseUnit(argv[2]);

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
		throw std::runtime_error("Incorrect number of arguments!");
	}
    return 0;
}
