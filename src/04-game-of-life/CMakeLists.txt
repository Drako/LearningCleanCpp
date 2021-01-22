add_library(gol_impl STATIC
	gol.cxx gol.hxx
	world.hxx
	renderer.hxx
	stream_renderer.hxx stream_renderer.cxx
	)

add_executable(04-game-of-life main.cxx)
target_link_libraries(04-game-of-life PRIVATE gol_impl)

add_executable(04-game-of-life-test test.cxx)
target_link_libraries(04-game-of-life-test PRIVATE gol_impl gtest gtest_main)
add_test(NAME 04-game-of-life-test COMMAND 04-game-of-life-test)
