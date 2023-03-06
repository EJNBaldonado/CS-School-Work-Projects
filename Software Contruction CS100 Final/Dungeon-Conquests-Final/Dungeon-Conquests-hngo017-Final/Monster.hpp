#ifndef __MONSTER_HPP__
#define __MONSTER_HPP__

class Monster{
	public:
		// note from Harrison: please use camelCase for function and variable names (first letter undercase) as per naming conventions.
		virtual void setAttack(int val) = 0;
		virtual void setPhysicalDef(int val) = 0;
		virtual void setMagicalDef(int val) = 0;
		virtual void setMaxHealth(int val) = 0;
		virtual int getMaxHealth() = 0;
		virtual int getAttack() = 0;
		virtual int getMagicalDef() = 0;
		virtual int getPhysicalDef() = 0;
		virtual int monsterHit() = 0;
		virtual string monsterType() = 0;
	protected:
		int maxHealth;
		int attack;
		int physicalDef;
		int magicalDef;
};

#endif
