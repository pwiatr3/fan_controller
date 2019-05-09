#include "Fan.hpp"
#include <thread>
#include <chrono>
#include <cmath>

using namespace std::literals::chrono_literals;

Fan::Fan() : rpm(0) {}

Fan::Fan(Fan&& other) : rpm(other.rpm) {
    other.rpm = 0;
}

void Fan::setSpeed(int newRpm) {
    auto difference = std::abs(newRpm - rpm);
    for (auto i = 0; i < difference; ++i) {
        if (newRpm - rpm > 0) {
            rpm++;
        } else {
            rpm--;
        }
        std::this_thread::sleep_for(1ms);
    }
}

int Fan::getSpeed() {
    return rpm;
}
