#ifndef __MAGIC_ITEM__
#define __MAGIC_ITEM__

#include "Item.hpp"

class MagicItem : public Item {
	public:

                MagicItem(){
                        rarity = rand() % 3;
                }

		void setRarity(){
			int rar = rand() % 3;
			rarity = rar;
			return;
		}
		
		int getRarity() {
			return rarity;
		}
		
		void printItem(int rar){
                        if (rar == 0) {
                                cout << "You found a Common Magic Ring!" << endl;
                        }
                        else if (rar == 1) {
                                cout << "You found an Uncommon Magic Necklace!" << endl;
                        }
                        else {
                                cout << "You found a Rare Magic Tome!" << endl;
                        }	
		}		

		void equip(Player* &player){
                        if (this->getRarity() == 0) {
                                cout << "You equipped the Common Magic Ring! You feel tingles through your skin. " << endl;
				player->Stats->allocatePoints(0,static_cast<int>(player->Stats->getMind()* .1),0);
				return;
                        }
                        else if (this->getRarity() == 1) {
                                cout << "You equipped the Uncommon Magic Necklace! Your magic feels stronger." << endl;
				player->Stats->allocatePoints(0,static_cast<int>(player->Stats->getMind()* .2),0);
				return;
                        }
                        else {
                                cout << "You equipped the Rare Magic Tome! Raw Magical energy courses through your body." << endl;
                        	player->Stats->allocatePoints(0,static_cast<int>(player->Stats->getMind()* .3),0);
				return;
			}
		}
	public:
		int rarity;
};

#endif
