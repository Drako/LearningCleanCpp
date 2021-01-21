#include "fiddle.hxx"

#include <cstddef>

#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <memory>

struct Foo {
    std::unique_ptr<int> bar;
    std::unique_ptr<int> baz;
};

void foo() {
    auto p3 = std::make_unique<Foo>(std::make_unique<int>(23), std::make_unique<int>(42));
    Foo* p4 = p3.get();
    std::unique_ptr<Foo> p{
        new Foo{
            std::unique_ptr<int>{new int{23}},
            std::unique_ptr<int>{new int{42}}
    }
    };


    std::shared_ptr<int> p5 = std::make_shared<int>(1337);
    std::shared_ptr<int> p8{ p5 };
    std::weak_ptr<int> p6{ p5 };
    {
        auto p7 = p6.lock();
    }
}

auto n = 0;

// variabler Zeiger, variable Daten
int* p = nullptr;

// variabler Zeiger, konstante Daten
const int* p2 = nullptr;
int const* p3 = nullptr;

// konstanter Zeiger, variable Daten
int* const p4 = nullptr;

// konstanter Zeiger, konstante Daten
const int* const p5 = nullptr;
int const* const p6 = nullptr;

int add(int const a, int const b) {
    return a + b;
}
