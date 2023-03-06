#include "Stat.hpp"

        Stat::Stat(){
		this->maxHealthVal = 100;
		this->physicalAtkVal = 10;
		this->magicAtkVal = 0;
		this->defenseVal = 0;
		this->bodyVal = 0;
		this->mindVal = 0;
		this->spiritVal = 0;
	} 
	Stat::Stat(int baseAttack, int baseHealth){
		this->physicalAtkVal = baseAttack;
		this->maxHealthVal = baseHealth;
	}

	Stat::~Stat(){
		delete this;
	}
	void Stat::allocatePoints(int body, int mind, int spirit){
		this->bodyVal += body;
		this->mindVal += mind;
		this->spiritVal += spirit;
		calculateNewStats();
	}

	void Stat::calculateNewStats(){
		this->physicalAtkVal = 10  + (this->bodyVal * 2);
		this->maxHealthVal = 100 + (this->bodyVal * 5 + this->spiritVal*10);
		this->defenseVal = (this->spiritVal);
		this->magicAtkVal = (this->mindVal * 3);
	}

	double Stat::getBody(){
		return this->bodyVal;
	}
	double Stat::getMind(){
		return this->mindVal;
	}
	double Stat::getSpirit(){
		return this->spiritVal;
	}
	double Stat::getPhysicalAtk(){
		return this->physicalAtkVal;
	}
	double Stat::getMaxHealth(){
		return this->maxHealthVal;
	}
	double Stat::getDefense(){ 
		return this->defenseVal;
	}
	double Stat::getMagicAtk(){
		return this->magicAtkVal;
	}
