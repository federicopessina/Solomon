find_package(GTest REQUIRED)

add_executable(OrderBook.Core.Test
        test.cpp
)

target_link_libraries(OrderBook.Core.Test
        PRIVATE
        OrderBook.Core
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(OrderBook.Core.Test
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GoogleTest)

gtest_discover_tests(OrderBook.Core.Test)