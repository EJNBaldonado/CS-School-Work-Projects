#ifndef __MAGIC_CHEST__
#define __MAGIC_CHEST__

#include "Chest.hpp"
#include "MagicItem.hpp"

class MagicChest : public Chest {
        public:
		~MagicChest(){
			delete this;
		}
                
		Item* itemFinder(){
			return new MagicItem();
		}
};

#endif

