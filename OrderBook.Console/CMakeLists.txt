add_executable(OrderBook.Console
        OrderBook.Console.cpp
        OrderBook.Console.h
)

target_link_libraries(OrderBook.Console
        PRIVATE
        OrderBook.Core
)

target_include_directories(OrderBook.Console
        PRIVATE
        ${CMAKE_SOURCE_DIR}/OrderBook.Core
)