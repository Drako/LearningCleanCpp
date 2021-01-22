#include <gtest/gtest.h>

#include <array>

#include "point.hxx"

/*
void do_something_with_point(Point const& p);
void do_something_with_string(std::string const& str);

do_something_with_point(Point{ 10 }); // explicit conversion
do_something_with_string("10"); // implicit conversion
*/

TEST(PointTest, canCreatePoint) {
    std::array<Point, 3u> const points{
        Point{},
        Point{0, 0},
        Point{0},
    };

    Point p2{ points[0] };

    Point const expected{0, 0};

    expected == points[0u];

    for (auto const& p : points) {
        EXPECT_EQ(p, expected);
    }
}

TEST(PointTest, canAddPoints) {
    Point const p1{ 10, 12 };
    Point const p2{ 13, 30 };

    auto const sum = p1 + p2;
    auto const expected = Point{ 23, 42 };
    EXPECT_EQ(sum, expected);
}

TEST(PointTest, canAddPointsModifying) {
    Point const p1{ 10, 12 };
    Point const p2{ 13, 30 };

    auto sum = p1;
    sum += p2;
    auto const expected = Point{ 23, 42 };
    EXPECT_EQ(sum, expected);
}

TEST(PointTest, canPreIncrementPoint) {
    Point p{ 10, 10 };
    Point const p2 = ++p;

    Point const expected{ 11, 11 };

    EXPECT_EQ(p, expected);
    EXPECT_EQ(p2, expected);
}

TEST(PointTest, canPostIncrementPoint) {
    Point p{ 10, 10 };
    Point const p2 = p++;

    Point const expected{ 11, 11 };

    EXPECT_EQ(p, expected);
    EXPECT_NE(p2, expected);
}

TEST(PointTest, canDownScalePoint) {
    static_assert(
        Point{ 10, 10 } / 5 == Point{ 2, 2 },
        "can divide at compile time"
    );

    Point const p{ 10, 10 };
    Point const actual = p / 0;

    Point const expected{ 2, 2 };

    EXPECT_EQ(actual, expected);
}
