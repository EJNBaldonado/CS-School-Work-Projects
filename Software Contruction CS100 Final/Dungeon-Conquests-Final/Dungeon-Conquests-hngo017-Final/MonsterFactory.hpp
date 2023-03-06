#ifndef  __MONSTER_FACTORY_HPP__
#define  __MONSTER_FACTORY_HPP__

#include "Monster.hpp"
#include "Dwarf.cpp"
#include "Normal.cpp"
#include "Ghost.cpp"
#include <stdlib.h>
#include <time.h>


class MonsterFactory {
    public:	
	MonsterFactory();
	MonsterFactory(int _floor);
        ~MonsterFactory();	
	// generates a monster with stats based off the floor the player is on 
	Monster* getMonster();
	int getFloor();
		
    private: 
	Monster* randomMonster;
	int floor;
	
	/*double health 
	double healthMin;
	double healthMax;
	double attackMin;
	double attackMax;
	double physicalDefMin;
	double physicalDefMax;
	double magicalDefMin;
	double magicalDefMax;*/
};

#endif
