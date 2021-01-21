add_executable(02-linked-list-test linked_list.hxx test.cxx)
target_link_libraries(02-linked-list-test PRIVATE gtest gtest_main)
add_test(NAME 02-linked-list-test COMMAND 02-linked-list-test)
