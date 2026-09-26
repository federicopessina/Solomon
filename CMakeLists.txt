cmake_minimum_required(VERSION 3.16)

project(Solomon LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTING "Build tests" ON)

enable_testing()

add_subdirectory(OrderBook.Core)
add_subdirectory(OrderBook.Console)

if(BUILD_TESTING)
add_subdirectory(OrderBook.Core.Test)
endif()