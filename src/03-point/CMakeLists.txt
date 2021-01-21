add_executable(03-point-test point.hxx test.cxx)
target_link_libraries(03-point-test PRIVATE gtest gtest_main)
add_test(NAME 03-point-test COMMAND 03-point-test)
