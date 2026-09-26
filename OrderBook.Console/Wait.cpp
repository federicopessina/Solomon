//
// Created by federico on 9/26/26.
//

#include "Wait.h"

#include <chrono>
#include <thread>

void wait()
{
    using namespace std::chrono_literals;

    std::this_thread::sleep_for(10ns);
    std::this_thread::sleep_until(
        std::chrono::system_clock::now() + 1s
    );
}