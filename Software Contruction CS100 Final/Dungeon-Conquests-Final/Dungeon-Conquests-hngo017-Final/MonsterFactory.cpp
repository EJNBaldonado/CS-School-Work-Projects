#include "MonsterFactory.hpp"

#include <stdlib.h>
#include <time.h>

	MonsterFactory::MonsterFactory() {
		
		this->floor = 1;
		randomMonster = nullptr;	
	}
	MonsterFactory::~MonsterFactory(){
		delete this->randomMonster;
	}
	MonsterFactory::MonsterFactory(int _floor){
		
		this->floor = _floor;
		randomMonster = nullptr;
	}

	int MonsterFactory::getFloor(){
		return this->floor;
	}

	// generates a random monster based off the floor the player is on 
	Monster* MonsterFactory::getMonster(){
		srand(time(NULL)); // initializes a random seed (makes rand actually random);
		int difficulty = this->floor * this->floor;			
		 
		int monsterType = rand() % 3;
		int normAtk = (rand() %  difficulty) +  (difficulty);
		int  normPDef =(rand() % difficulty) + (difficulty);
		int  normMDef = (rand() % difficulty) + (difficulty);
                int  normHth = 10 * (rand() %  difficulty) + (difficulty);

		if (monsterType == 0){
			delete randomMonster;
			randomMonster = new Normal(normHth, normAtk, normPDef, normMDef); 
			return randomMonster;
		} 
		else if (monsterType == 1){
			delete randomMonster;
			randomMonster = new Ghost(normHth, normAtk, normPDef, normMDef); 
			return randomMonster;
		}
		else{
			delete randomMonster;
			randomMonster = new Dwarf(normHth, normAtk, normPDef, normMDef); 
			return randomMonster;
		}                
	}
