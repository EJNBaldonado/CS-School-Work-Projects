#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include "Player.cpp"

class Item {
	public:
		virtual void printItem(int rar) = 0;
		virtual int getRarity() = 0;
		virtual void equip(Player* &player) = 0;
};

#endif
