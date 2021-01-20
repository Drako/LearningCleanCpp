#include <iostream>

#include "fiddle.hxx"

int main() {
    int a, b;

    std::cout << "a: ";
    std::cin >> a;

    std::cout << "b: ";
    std::cin >> b;

    std::cout << "a + b = " << add(a, b) << std::endl;
    return 0;
}
