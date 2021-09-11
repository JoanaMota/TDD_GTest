#include <gtest/gtest.h>
#include "../include/functions.hpp"

TEST(Functions, Division)
{
    EXPECT_EQ(division(4, 2), 2);
    EXPECT_EQ(division(4, 0), 0);
}