#ifndef __NORMAL_HPP__
#define __NORMAL_HPP__
#include "Monster.hpp"

class Normal : public Monster {
        public:
                Normal(int Hth, int Atk, int PDef, int Mdef);
		~Normal();
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

