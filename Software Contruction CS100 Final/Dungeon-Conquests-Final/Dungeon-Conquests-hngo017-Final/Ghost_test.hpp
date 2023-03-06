#ifndef __GHOST__TEST__HPP__
#define __GHOST__TEST__HPP__
#include "gtest/gtest.h"
#include "testIncludeFile.hpp"

TEST(GhostTest, getMaxHealth_Test){
	      Ghost* GhostTest = new Ghost(0, 0, 0, 0);
	      GhostTest->setMaxHealth(50);
	      EXPECT_EQ(GhostTest->getMaxHealth(),50);
}

TEST(GhostTest, getAttack_Test){
	      Ghost* GhostTest = new Ghost(0, 0, 0, 0);
	      GhostTest->setAttack(20);
	      EXPECT_EQ(GhostTest->getAttack(),20);
}

TEST(GhostTest, getMagicalDef_Test){
        Ghost* GhostTest = new Ghost(0, 0, 0, 0);
	      GhostTest->setMagicalDef(20);
	      EXPECT_EQ(GhostTest->getMagicalDef(),20);
}

TEST(GhostTest, getPhysicalDef){
	      Ghost* GhostTest = new Ghost(0, 0, 0, 0);
	      GhostTest->setPhysicalDef(20);
	      EXPECT_EQ(GhostTest->getPhysicalDef(),20);
}
            
#endif
