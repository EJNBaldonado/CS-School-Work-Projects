#ifndef __STAT_TEST_HPP__
#define __STAT_TEST_HPP__

#include "gtest/gtest.h"
#include "../testIncludeFile.hpp"

TEST(StatTest, constructorTest){
    Stat* statTest1 = new Stat();
    EXPECT_EQ(statTest1->getMaxHealth(), 100);

    // calls Stat's 2 argument constructor with base attack and health
    Stat* statTest2 = new Stat(15, 100);
    EXPECT_EQ(statTest2->getPhysicalAtk(), 15);
}

TEST(StatTest, baseStatTest){
    Stat* statTest = new Stat();
    // allocates 3 points in body, 4 in mind, 5 in spirit
    statTest->allocatePoints(3, 4, 5);
    EXPECT_EQ(statTest->getMind(), 4);
}

TEST(StatTest, compositeStatTest){
    Stat* statTest = new Stat();
    // allocates 3 points in body, 4 in mind, 5 in spirit
    statTest->allocatePoints(4, 3, 5);
    EXPECT_EQ(statTest->getMaxHealth(), (100 + 4*5 + 5*10) );

    statTest->allocatePoints(1, 3, 2);
    EXPECT_EQ(statTest->getMagicAtk(), ( 6 * 3 ) );
}

#endif // __STAT_TEST_HPP__
