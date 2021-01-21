#include <gtest/gtest.h>

#include "fizzbuzz.hxx"

TEST(FizzBuzzTest, returnsFizzOnDivisibleBy3) {
    EXPECT_EQ(fizzbuzz(3), "Fizz");
    EXPECT_EQ(fizzbuzz(6), "Fizz");
    EXPECT_EQ(fizzbuzz(9), "Fizz");
    EXPECT_EQ(fizzbuzz(12), "Fizz");
    EXPECT_EQ(fizzbuzz(18), "Fizz");
    EXPECT_EQ(fizzbuzz(21), "Fizz");
    EXPECT_EQ(fizzbuzz(24), "Fizz");
    EXPECT_EQ(fizzbuzz(27), "Fizz");
}

TEST(FizzBuzzTest, returnsBuzzOnDivisibleBy5) {
    EXPECT_EQ(fizzbuzz(5), "Buzz");
    EXPECT_EQ(fizzbuzz(10), "Buzz");
    EXPECT_EQ(fizzbuzz(20), "Buzz");
    EXPECT_EQ(fizzbuzz(25), "Buzz");
}

TEST(FizzBuzzTest, returnsFizzBuzzOnDivisibleBy15) {
    EXPECT_EQ(fizzbuzz(15), "FizzBuzz");
    EXPECT_EQ(fizzbuzz(30), "FizzBuzz");
}

TEST(FizzBuzzTest, returnsStringifiedNumber) {
    EXPECT_EQ(fizzbuzz(1), "1");
    EXPECT_EQ(fizzbuzz(2), "2");
    EXPECT_EQ(fizzbuzz(4), "4");
    EXPECT_EQ(fizzbuzz(7), "7");
    EXPECT_EQ(fizzbuzz(8), "8");
    EXPECT_EQ(fizzbuzz(11), "11");
    EXPECT_EQ(fizzbuzz(13), "13");
    EXPECT_EQ(fizzbuzz(14), "14");
    EXPECT_EQ(fizzbuzz(16), "16");
    EXPECT_EQ(fizzbuzz(17), "17");
    EXPECT_EQ(fizzbuzz(19), "19");
    EXPECT_EQ(fizzbuzz(22), "22");
    EXPECT_EQ(fizzbuzz(23), "23");
    EXPECT_EQ(fizzbuzz(26), "26");
    EXPECT_EQ(fizzbuzz(28), "28");
    EXPECT_EQ(fizzbuzz(29), "29");
}
