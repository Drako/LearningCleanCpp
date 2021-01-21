#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "fizzbuzz.hxx"


int main() {
    add(23, 42);

    std::vector<int> doubled;

    std::vector<int> const numbers{ 1, 2, (23, "23", 5) };
    /*std::vector<int> doubled(3);
    for (auto n = numbers.size(); n--;)
        doubled[n] = numbers[n] * 2;*/

    doubled.reserve(3);
    /*for (auto const n : numbers) {
        doubled.push_back(n);
    }*/
    std::transform(
        std::cbegin(numbers),
        std::cend(numbers),
        std::back_inserter(doubled),
        [](int n) { return n * 2; }
    );




    std::generate_n(
        std::ostream_iterator<std::string>(std::cout, "\n"),
        100,
        [n=0]() mutable { return fizzbuzz(++n); }
    );
    return 0;
}
