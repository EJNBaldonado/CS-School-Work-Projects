
#include "Normal.hpp"

Normal::Normal(int Hth, int Atk, int PDef, int MDef){
	maxHealth = Hth;
	attack = Atk;
	physicalDef = PDef;
	magicalDef = MDef;
}

Normal::~Normal(){
	delete this;
}

int Normal::monsterHit(){
	return static_cast<int>(.55 * (attack + ((rand() % attack))));
}

void Normal::setAttack(int val){
	this->attack = val;
}

void Normal::setMaxHealth(int val){
	this->maxHealth = val;
}

void Normal::setPhysicalDef(int val){
	this->physicalDef = val;
}

void Normal::setMagicalDef(int val){
	this->magicalDef = val;
}

int Normal::getMaxHealth(){
	return this->maxHealth;
}

int  Normal::getAttack(){
	return this->attack;
}

int Normal::getMagicalDef(){
	return this->magicalDef;
}

int Normal::getPhysicalDef(){
	return this->physicalDef;
}


string Normal::monsterType() {
	string type = "Normal Monster";
	return type;
}

