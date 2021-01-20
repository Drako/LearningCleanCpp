#include <iostream>

#include "fizzbuzz.hxx"

int main() {
    for (auto n = 1u; n <= 100u; ++n)
        std::cout << fizzbuzz(n) << std::endl;
    return 0;
}
