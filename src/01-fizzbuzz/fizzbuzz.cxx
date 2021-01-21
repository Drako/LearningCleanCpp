#include "fizzbuzz.hxx"

#include <ostream>

namespace {
    using namespace std::literals::string_literals;

    std::string fizz(unsigned const n) {
        return n % 3u ? ""s : "Fizz"s;
    }

    std::string buzz(unsigned const n) {
        return n % 5u ? ""s : "Buzz"s;
    }
}

std::string fizzbuzz(unsigned const n) {
    auto const fb = fizz(n) + buzz(n);
    return fb.empty() ? std::to_string(n) : fb;
}

void run_fizzbuzz(std::ostream& out) {
    for (auto n = 1u; n <= 100u; ++n)
        out << fizzbuzz(n) << std::endl;
}
