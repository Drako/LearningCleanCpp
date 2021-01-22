#pragma once

#ifndef POINT_HXX
#define POINT_HXX

#include <cctype>
#include <ostream>
#include <exception>

struct division_by_zero : std::runtime_error {
    division_by_zero(std::string const & message)
        : std::runtime_error{message}
    {}
};

namespace {
    std::string make_indent(int depth) {
        std::string indent{};

        std::string indentation = "        ";
        while (depth > 8) {
            indent += indentation;
            depth -= 8;
        }

        indentation[depth] = '\0';
        indent += indentation;
        return indent;
    }

    template <typename A, typename B>
    auto add(A a, B b) -> decltype(a + b) {
        return a + b;
    }

    auto to_upper(std::string str) -> std::string {
        std::transform(
            std::cbegin(str),
            std::cend(str),
            std::begin(str),
            [](char c) -> char { return std::toupper(c); }
        );
        return str;
    }
}

/*struct BasicPoint {
    virtual std::string to_string(int indent = 4) const {
        return make_indent(indent) + "{}";
    };
};

void deal_with_point(BasicPoint const* bp) {
    bp->to_string();
}*/

struct Point final /*: BasicPoint*/ {

    int x{};
    int y{};

    /*std::string to_string(int indent) const {
        return make_indent(indent) + std::to_string(x) + " " + std::to_string(y);
    }*/

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

struct Base {
    virtual ~Base() = default;
};
struct Inherited : Base {
    void foo() {}
};

constexpr Point operator / (Point const& lhs, int divisor) {
    assert(divisor != 0);

    /*
    !!expr
    static_cast<bool>(expr)
        (bool)expr
        bool(expr)
        bool{expr}
    */


    Point p = static_cast<Point>(10);
    

    /*if (divisor == 0) {
        throw division_by_zero{ "divisor must not be 0" };
    }*/
    return { lhs.x / divisor, lhs.y / divisor };
}

constexpr Point& operator += (Point& lhs, Point const& rhs) {
    return lhs = lhs + rhs;
}

struct const_int {
    int const value;
};

const_int operator""_ci(unsigned long long value) {
    return { static_cast<int>(value) };
}

const_int operator - (const_int self) {
    return { -self.value };
}

int const* operator & (const_int const& ci) {
    return &ci.value;
}

template <typename T>
void show_address(T const& val) {
    std::cout << std::addressof(val) << std::endl;
}

auto const val = -23_ci;

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

template <bool IsEqual>
struct foo {};


foo < Point{} == Point{ 23, 42 } > ;
foo<false>;

#include <typeinfo>

double const PI = 3.1415926;

void const_cast_away(double const* dcp) {
    //double const* dcp = &d; // &PI;

    // mostly bad
    double* dp = const_cast<double*>(dcp);
    *dp = 3.0;
}

std::ostream& operator << (std::ostream& os, Point const& p) {
    // RTTI -> RunTime Type Information

    Base* bp = new Inherited{};
    std::type_info const& info = typeid(bp);
    Inherited* ip = dynamic_cast<Inherited*>(bp);
    if (ip) {
        ip->foo();
    }
    delete bp;

    const_int ci{ 23 };
    // mostly evil
    int i = *reinterpret_cast<int*>(&ci);
    auto addr = reinterpret_cast<std::uintptr_t>(&ci);
    auto ptr = reinterpret_cast<const_int*>(0x0BADCAFEC0FFEE00);

    return os << "{" << p.x << ", " << p.y << "}";
}

#endif // POINT_HXX
