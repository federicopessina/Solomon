# CMakeList.txt : CMake project for OrderBook.Console, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (OrderBook.Console "OrderBook.Console.cpp" "OrderBook.Console.h")

#include_directories(${CMAKE_SOURCE_DIR}/OrderBook.Core)

# TODO: Add tests and install targets if needed.
target_link_libraries (OrderBook.Core)

