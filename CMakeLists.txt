cmake_minimum_required(VERSION 3.15)
cmake_policy(VERSION 3.15)
project(LearningCleanCpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(contrib)
add_subdirectory(src)
