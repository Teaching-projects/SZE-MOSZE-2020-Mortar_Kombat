#include "Character.h"

Character::Character(const std::string characterName, const unsigned int healthPoints, const unsigned int damagePoints) : name(characterName), DMG(damagePoints)
{
	HP = healthPoints;
}

std::vector<std::string> Character::parseUnit(std::string fileName)
{
	std::ifstream sourceFile(fileName);
	if (sourceFile.good())
	{
        //0. get file name without extension
        fileName.resize(fileName.length() - 5);

		//1. run conversion script
		std::string command = "\
		python json2txt.py \
		";
		command.append(fileName);
		system(command.c_str());

		//2. use the .txt
        std::ifstream outputFile(fileName + ".txt");
        std::string line;
        std::vector<std::string> characterAttributes;
        while (std::getline(outputFile, line))
        {
            characterAttributes.push_back(line);
        }

        //3. delete the .txt
        std::remove((fileName + ".txt").c_str());

        //finally return
        return characterAttributes;
	}
	else
	{
		//later to be adjusted !!!!!!!!!!!!!
		throw std::runtime_error("File not found!");
	}
}

const std::string Character::getName() const
{
	return name;
}

const unsigned int Character::getHP() const
{
	return HP;
}

const unsigned int Character::getDMG() const
{
	return DMG;
}

void Character::gotHit(const unsigned int damagePoints)
{
    if (int(HP - damagePoints) > 0)
    {
        HP = HP - damagePoints;
    }
    else
    {
        HP = 0;
    }
}
