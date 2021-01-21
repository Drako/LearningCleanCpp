add_library(fiddle_impl STATIC fiddle.hxx fiddle.cxx)

add_executable(fiddle main.cxx)
target_link_libraries(fiddle PRIVATE fiddle_impl)

add_executable(fiddle-test test.cxx)
target_link_libraries(fiddle-test PRIVATE fiddle_impl gtest gmock gmock_main)
add_test(NAME fiddle-test COMMAND fiddle-test)
