add_library(fizzbuzz_impl STATIC fizzbuzz.cxx fizzbuzz.hxx)

add_executable(01-fizzbuzz main.cxx)
target_link_libraries(01-fizzbuzz PRIVATE fizzbuzz_impl)

add_executable(01-fizzbuzz-test test.cxx)
target_link_libraries(01-fizzbuzz-test PRIVATE fizzbuzz_impl gtest gtest_main)
add_test(NAME 01-fizzbuzz-test COMMAND 01-fizzbuzz-test)
