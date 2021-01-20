#pragma once

#ifndef FIZZBUZZ_HXX
#define FIZZBUZZ_HXX

#include <string>

/**
 * Returns "Fizz", if [n] is divisible by 3,
 * "Buzz", if it is divisible by 5,
 * and "FizzBuzz" if it is divisible by both.
 * 
 * In any other case [n] is returned as a string.
 * 
 * Examples:
 * 
 * fizzbuzz(1) -> "1"
 * fizzbuzz(3) -> "Fizz"
 * fizzbuzz(5) -> "Buzz"
 * fizzbuzz(15) -> "FizzBuzz"
 */
std::string fizzbuzz(unsigned n);

#endif // FIZZBUZZ_HXX
