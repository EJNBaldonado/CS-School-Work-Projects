#ifndef __GHOST_HPP__
#define __GHOST_HPP__
#include "Monster.hpp"

class Ghost : public Monster {
        public:
                Ghost(int Hth, int Atk, int PDef, int Mdef);
                ~Ghost();

		// note from Harrison: please use camelCase for function and variable names (first letter undercase) as per naming conventions.
		 void setAttack(int val);
                 void setPhysicalDef(int val);
                 void setMagicalDef(int val);
                 void setMaxHealth(int val);
                 int  getMaxHealth();
                 int getAttack();
                 int getMagicalDef();
                 int getPhysicalDef();
                 int monsterHit();
		 string monsterType();


};

#endif

