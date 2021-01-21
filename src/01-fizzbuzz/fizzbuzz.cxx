#include "fizzbuzz.hxx"

#include <iostream>
#include <regex>

using namespace std::literals::string_literals;

std::regex operator""_re(char const* const str, std::size_t) {
    return std::regex{ str };
}

class Condition {
    unsigned divisor;
    std::string word;

public:
    Condition(unsigned divisor, std::string word)
        : divisor{divisor}
        , word{std::move(word)}
    {}

    std::string operator() (unsigned n) const {
        R"(^(\.)$)"_re;

        return n % divisor ? ""s : word;
    }
};

int add(int a, int b) { return a + b; }

namespace {
    auto condition(unsigned divisor, std::string word) {
        return Condition{ divisor, std::move(word) };

        //return [divisor, word=std::move(word)](unsigned n) {
        //    return n % divisor ? "" : word;
        //};
    }
}

std::string fizzbuzz(unsigned n) {
    static auto const fizz = condition(3, "Fizz");
    static auto const buzz = condition(5, "Buzz");

    auto const fb = fizz(n) + buzz(n);
    return fb.empty() ? std::to_string(n) : fb;
}
