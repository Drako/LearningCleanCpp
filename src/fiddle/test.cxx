#include <gtest/gtest.h>

#include "fiddle.hxx"

TEST(FiddleTest, add) {
    EXPECT_EQ(add(1, 1), 2);
}

#include <type_traits>

template <typename Type>
struct has_run_method {
    template <typename T = decltype(&Type::run)>
    static std::true_type check(int);

    static std::false_type check(...);

    static auto const value = decltype(check(24))::value;
};

static_assert(
    std::has_virtual_destructor_v<Runnable>,
    "Interface should have virtual destructor."
);

static_assert(
    has_run_method<Runnable>::value,
    "Runnable should have a run method."
);
