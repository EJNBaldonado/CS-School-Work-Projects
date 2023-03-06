#include "Dwarf.hpp"

Dwarf::Dwarf(int Hth, int Atk, int PDef, int MDef){
	maxHealth = Hth;
	attack = Atk;
	physicalDef = static_cast<int>(.5 * PDef);
	magicalDef = static_cast<int>(2 * MDef);
}

Dwarf::~Dwarf(){
	delete this;
}

int Dwarf::monsterHit(){
	return static_cast<int>(.55 * (attack + ((rand() % attack))));
}

void Dwarf::setAttack(int val){
	this->attack = val;
}

void Dwarf::setMaxHealth(int val){
	this->maxHealth = val;
}

void Dwarf::setPhysicalDef(int val){
	this->physicalDef = val;
}

void Dwarf::setMagicalDef(int val){
	this->magicalDef = val;
}

int Dwarf::getMaxHealth(){
	return this->maxHealth;
}

int  Dwarf::getAttack(){
	return this->attack;
}

int Dwarf::getMagicalDef(){
	return this->magicalDef;
}

int Dwarf::getPhysicalDef(){
	return this->physicalDef;
}


string Dwarf::monsterType() {
        string type = "Dwarf";
	return type;
}

