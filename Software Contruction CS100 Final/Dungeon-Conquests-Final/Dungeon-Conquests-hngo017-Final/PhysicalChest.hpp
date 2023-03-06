#ifndef __PHYSICAL_CHEST__
#define __PHYSICAL_CHEST__

#include "Chest.hpp"
#include "PhysicalItem.hpp"
class PhysicalChest : public Chest {
        public:
                ~PhysicalChest(){
			delete this;
		}
                Item* itemFinder(){
			return new PhysicalItem();
		}
};

#endif

