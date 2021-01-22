#pragma once

#ifndef POINT_HXX
#define POINT_HXX

#include <cctype>
#include <ostream>
#include <exception>

struct division_by_zero : std::runtime_error {
    inline division_by_zero(std::string const & message)
        : std::runtime_error{message}
    {}
};

struct Point final {

    int x{};
    int y{};

    constexpr Point() = default;

    constexpr Point(int x, int y) : x{ x }, y{ y } {}

    constexpr explicit Point(int value) : x{value}, y{value} {}

    constexpr bool is_equal(Point const& p) const {
        return x == p.x && y == p.y;
    }

    constexpr Point& operator = (Point const& rhs) {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
};

template <typename Comparable>
constexpr bool operator == (Comparable const & lhs, Comparable const& rhs) {
    return lhs.is_equal(rhs);
}

template <typename Comparable>
constexpr bool operator != (Comparable const& lhs, Comparable const& rhs) {
    return !lhs.is_equal(rhs);
}

constexpr Point operator + (Point const& lhs, Point const& rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

constexpr Point operator / (Point const& lhs, int divisor) {
    if (divisor == 0) {
        throw division_by_zero{ "divisor must not be 0" };
    }
    return { lhs.x / divisor, lhs.y / divisor };
}

constexpr Point& operator += (Point& lhs, Point const& rhs) {
    return lhs = lhs + rhs;
}

constexpr Point& operator ++(Point& self) {
    ++self.x;
    ++self.y;
    return self;
}

constexpr Point operator++(Point& self, int) {
    auto const old = self;
    ++self;
    return old;
}

#endif // POINT_HXX
