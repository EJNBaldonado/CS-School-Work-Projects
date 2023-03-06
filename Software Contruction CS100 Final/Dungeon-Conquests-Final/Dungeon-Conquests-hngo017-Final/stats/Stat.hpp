#ifndef __STAT_HPP__
#define __STAT_HPP__

// #include "../Player.hpp"

using namespace std;
class Stat { 
    public:
        Stat();
	Stat(int baseAttack, int baseHealth);
	void allocatePoints(int body, int mind, int spirit);
	~Stat();
	double getBody();
	double getMind();
	double getSpirit();
	double getPhysicalAtk();
	double getMaxHealth();
	double getDefense();
	double getMagicAtk();

    private:
	void calculateNewStats();

	double bodyVal;
	double mindVal;
	double spiritVal;
	double physicalAtkVal;
	double maxHealthVal;
	double defenseVal;
	double magicAtkVal;
};

#endif //__STAT_HPP__
