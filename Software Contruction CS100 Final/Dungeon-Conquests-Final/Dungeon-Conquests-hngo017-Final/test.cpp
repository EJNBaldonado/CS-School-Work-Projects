#include "gtest/gtest.h"

#include "stats/stat_test.hpp"
#include "Player_test.hpp"
#include "Normal_test.hpp"
#include "Dwarf_test.hpp"
#include "Ghost_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
