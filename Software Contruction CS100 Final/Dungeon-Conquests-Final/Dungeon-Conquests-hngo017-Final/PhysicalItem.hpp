#ifndef __PHYSICAL_ITEM__
#define __PHYSICAL_ITEM__

#include "Item.hpp"

class PhysicalItem : public Item {
        public:
		
		PhysicalItem(){
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
                                cout << "You found an Common Physical Glove!" << endl;
				return;
                        }
                        else if (rar == 1) {
                                cout << "You found some Uncommon Chains!" << endl;
				return;
                        }
                        else {
                                cout << "You found a Rare Physical Weapon!" << endl;
				return;
                        }
		}		
 
                void equip(Player* &player){
                        if (this->getRarity() == 0) {
				cout << "You equipped an Uncommon Physical Glove! You clench your fists tighter." << endl;
                                player->Stats->allocatePoints(static_cast<int>(player->Stats->getBody()* .1),0,0);
                                return;	
			}
			else if (this->getRarity() == 1) {
				cout << "You equipped the Common Physical Chains! Your strength increases." << endl;
                                player->Stats->allocatePoints(static_cast<int>(player->Stats->getBody()* .2),0,0);
                                return;
			}
			else {
				cout << "You equipped a Rare Physical Weapon! YEE-HAW! Blood courses through your veins!" << endl;
                                player->Stats->allocatePoints(0,static_cast<int>(player->Stats->getMind()* .3),0);
                                return;

			}
                }
	private:
		int rarity;
};

#endif
