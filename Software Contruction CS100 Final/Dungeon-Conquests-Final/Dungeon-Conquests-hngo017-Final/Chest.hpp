#ifndef __CHEST__
#define __CHEST__

#include "Item.hpp"

class Chest {
        public:
		virtual Item* itemFinder() = 0;
};

#endif
