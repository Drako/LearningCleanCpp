#include <gtest/gtest.h>

#include "fiddle.hxx"

TEST(FiddleTest, add) {
    EXPECT_EQ(add(1, 1), 2);
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(2, 2), 4);
    EXPECT_EQ(add(-1, 1), 0);
}
