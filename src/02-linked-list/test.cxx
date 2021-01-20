#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "linked_list.hxx"

TEST(LinkedListTest, test) {
    exercise::linked_list<int> numbers;
    EXPECT_EQ(numbers.length(), 0);
    EXPECT_TRUE(numbers.empty());

    numbers.push(10);
    EXPECT_EQ(numbers.length(), 1);
    EXPECT_FALSE(numbers.empty());

    EXPECT_EQ(numbers.pop(), 10);
    EXPECT_EQ(numbers.length(), 0);
    EXPECT_TRUE(numbers.empty());

    EXPECT_THROW(numbers.pop(), std::out_of_range);


    numbers.push(23);
    numbers.push(42);
    numbers.push(1337);

    std::vector<int> const expected{ 1337, 42, 23 };
    std::vector<int> actual;
    actual.reserve(3);
    numbers.for_each([&actual](int n) { actual.push_back(n); });
    EXPECT_EQ(expected, actual);
}
