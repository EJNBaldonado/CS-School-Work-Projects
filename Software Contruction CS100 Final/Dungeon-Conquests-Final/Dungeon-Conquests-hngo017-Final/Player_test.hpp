#ifndef __PLAYER__TEST__HPP__
#define __PLAYER__TEST__HPP__
#include "gtest/gtest.h"
#include "testIncludeFile.hpp"

TEST(PlayerTest, getExp_Test){
	Player* PlayerTest = new Player();
	PlayerTest->setExp(10);
	EXPECT_EQ(PlayerTest->getExp(),10);
}

TEST(PlayerTest, getLevel_Test){
	Player* PlayerTest = new Player();
	PlayerTest->setLevel(5);
	EXPECT_EQ(PlayerTest->getLevel(),5);
}

TEST(PlayerTest, getMaxHealth_Test){
	Player* PlayerTest = new Player();
	EXPECT_EQ(PlayerTest->getMaxHealth(),100);
}

TEST(PlayerTest, getName_Test){
	Player* PlayerTest = new Player();
	PlayerTest->setName("lucky");
	EXPECT_EQ(PlayerTest->getName(),"lucky");
}

TEST(PlayerTest, getCurrentHealth_Test){
	Player* PlayerTest = new Player();
	PlayerTest->setCurrentHealth(78);
	EXPECT_EQ(PlayerTest->getCurrentHealth(),78);
}

#endif
