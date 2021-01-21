#include <iostream>
#include <cmath>
#include <array>
#include <vector>

#include "fiddle.hxx"

void print(int n) {
    std::cout << "int" << std::endl;
}

void print(void* p) {
    std::cout << "void*" << std::endl;
}

template <typename T, std::size_t Size>
std::size_t array_size(T (&arr)[Size]) {
    return sizeof(arr) / sizeof(arr[0]);
}

double length(std::array<double, 3> vec) {

}

double length(std::array<double, 2> vec) {

}

struct point { int x, y, z; point(int x, int y, int z); };

//int main(int argc, char** argv, char** env);
int main(int argc, char** argv) {
    int arr[3];
    point p{1, 2, 3};

    int a{};

    std::array<double, 3> numbers{ 1, 2, 3 };
    std::cout << numbers.size() << std::endl;

    print(NULL);
    print(nullptr);

    int a, b;

    std::cout << "a: ";
    std::cin >> a;

    std::cout << "b: ";
    std::cin >> b;

    std::cout << "a + b = " << add(a, b) << std::endl;
    return 0;
}
