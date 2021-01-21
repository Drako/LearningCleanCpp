#include <gtest/gtest.h>

#include "fiddle.hxx"

TEST(FiddleTest, add) {
    EXPECT_EQ(add(1, 1), 2);
}
