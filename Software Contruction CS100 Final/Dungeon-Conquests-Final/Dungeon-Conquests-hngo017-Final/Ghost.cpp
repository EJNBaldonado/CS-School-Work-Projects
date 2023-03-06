#include "Ghost.hpp"

Ghost::Ghost(int Hth, int Atk, int PDef, int MDef){
        maxHealth = Hth;
        attack = Atk;
        physicalDef = static_cast<int>(2 * PDef);
        magicalDef = static_cast<int>(0.5 * MDef);
}

Ghost::~Ghost(){
	delete this;
}

int Ghost::monsterHit(){
        return static_cast<int>(.55 * (attack + ((rand() % attack))));
}

void Ghost::setAttack(int val){
	this->attack = val;
}

void Ghost::setMaxHealth(int val){
	this->maxHealth = val;
}

void Ghost::setPhysicalDef(int val){
	this->physicalDef = val;
}

void Ghost::setMagicalDef(int val){
	this->magicalDef = val;
}

int Ghost::getMaxHealth(){
	return this->maxHealth;
}

int  Ghost::getAttack(){
	return this->attack;
}

int Ghost::getMagicalDef(){
	return this->magicalDef;
}

int Ghost::getPhysicalDef(){
	return this->physicalDef;
}

string Ghost::monsterType() { 
	string type =  "Ghost";
	return type;
}
