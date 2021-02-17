cmake_minimum_required(VERSION 3.17)
project(classes)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIR})

add_executable(classes gcd.cpp)