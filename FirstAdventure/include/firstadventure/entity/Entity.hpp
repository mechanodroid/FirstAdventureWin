//
//  Entity.hpp
//  FirstAdventure
//
//  Created by David Paris on 25/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <string>
#include "Stats.hpp"
#include <vector>

using namespace::std;
class Command;
class EntityChildren;

/*
 Entity class is the main game object.  It holds a number of components, which can be populated or null.
 It is based on the Component pattern (http://www.gameprogrammingpatterns.com/component.html)
*/

const int MAXSPELLS = 10;

class Entity
{
public:

private:
    string description_;
	string mySpells[MAXSPELLS];
	int numSpells;


    Stats* stats_;
    Command* command_;
    Entity* parent_;
    EntityChildren* children_;
        	

public:

    Entity()
    {
        description_ = "";
        stats_ = nullptr;
        command_ = nullptr;
        parent_ = nullptr;
        children_ = nullptr;
		numSpells = 0;

    }
    
    Entity(std::string description) : description_{description}
    {
        stats_ = nullptr;
        command_ = nullptr;
        parent_ = nullptr;
        children_ = nullptr;
    }
    
    Entity(std::string description, Stats* stats, Command* command, Entity* parent, EntityChildren* children)
    : description_{description}, stats_{stats}, command_{command}, parent_{parent}, children_{children}
    {

    }
    
    ~Entity(){}
    
    std::string getDescription()
    {
        return description_;
    }

	void addSpell(std::string newSpell)
	{
		if (numSpells < MAXSPELLS)
		{
			mySpells[numSpells] = newSpell;
			numSpells++;
		}
	}

	void removeSpell(const std::string spellToRemove)
	{
		for (int i; i < numSpells; i++)
		{
			if (mySpells[i] == spellToRemove)
			{
				for (int j = i + 1; j < numSpells; j++)
				{
					mySpells[j - 1] = mySpells[j];
				}
				numSpells--;
			}
		}
	}

	std::string printSpells()
	{
		std::string returnResult;
		//Main Character - has two spells
		for (int i = 0; i < numSpells; i++)
		{
			std::string spell = mySpells[i];
			returnResult += spell;
			if (i < numSpells - 1)
			{
				 returnResult += ", ";
			}
		}
		return returnResult;
	}
    
    void setDescription(std::string description)
    {
        description_ = description;
    }
    
    Command* getCommand()
    {
        return command_;
    }
    
    void setCommand(Command* command)
    {
        command_ = command;
    }
    
    void setParentEntity(Entity* newParent)
    {
        parent_ = newParent;
    }
    
    Entity* getParentEntity()
    {
        return parent_;
    }
    
    Stats* getStats()
    {
        return stats_;
    }
    
    void setStats(Stats* stats)
    {
        stats_ = stats;
    }

    EntityChildren* getChildren()
    {
        return children_;
    }
    
    void setChildren(EntityChildren* children)
    {
        children_ = children;
    }
};

#endif /* Entity_hpp */
