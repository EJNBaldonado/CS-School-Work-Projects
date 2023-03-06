#ifndef __DWARF__TEST__HPP__
#define __DWARF__TEST__HPP__
#include "gtest/gtest.h"
#include "testIncludeFile.hpp"

TEST(DwarfTest, getMaxHealth_Test){
	Dwarf* DwarfTest = new Dwarf(0, 0, 0, 0);
	DwarfTest->setMaxHealth(50);
	EXPECT_EQ(DwarfTest->getMaxHealth(),50);
}

TEST(DwarfTest, getAttack_Test){
	Dwarf* DwarfTest = new Dwarf(0, 0, 0, 0);
	DwarfTest->setAttack(20);
	EXPECT_EQ(DwarfTest->getAttack(),20);
}

TEST(DwarfTest, getMagicalDef_Test){
        Dwarf* DwarfTest = new Dwarf(0, 0, 0, 0);
	DwarfTest->setMagicalDef(20);
	EXPECT_EQ(DwarfTest->getMagicalDef(),20);
}

TEST(DwarfTest, getPhysicalDef){
	Dwarf* DwarfTest = new Dwarf(0, 0, 0, 0);
	DwarfTest->setPhysicalDef(20);
	EXPECT_EQ(DwarfTest->getPhysicalDef(),20);
}

#endif
