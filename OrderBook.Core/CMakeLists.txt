# CMakeList.txt : CMake project for OrderBook.Core, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (OrderBook.Core "OrderBook.Core.cpp" "OrderBook.Core.h" "Order.h" "Order.cpp" "Book.cpp" "VolumeMap.h" "VolumeMap.cpp" "OrderConsole.h" "OrderConsole.cpp" "BookConsole.h" "BookConsole.cpp" "Exceptions/Store.Exception.h" "BidStore.h" "BidStore.cpp" "AskStore.h" "AskStore.cpp")

# TODO: Add tests and install targets if needed.
