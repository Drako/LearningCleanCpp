add_library(gildedrose_impl STATIC
	item.hxx
	shop.hxx shop.cxx
	)

add_executable(05-gilded-rose main.cxx)
target_link_libraries(05-gilded-rose PRIVATE gildedrose_impl)

add_executable(05-gilded-rose-test test.cxx)
target_link_libraries(05-gilded-rose-test PRIVATE gildedrose_impl gtest gtest_main)
add_test(NAME 05-gilded-rose-test COMMAND 05-gilded-rose-test)
