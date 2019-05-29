#include "Fan.hpp"
#include <stdexcept>
#include <cmath>

Fan::Fan() {
    rpm = 0;
}

void Fan::setSpeed(int newRpm) {
    constexpr int minRpm = 1000;
    constexpr int maxRpm = 3000;
    constexpr int disabledRpm = 0;

    if ((newRpm < minRpm and newRpm != disabledRpm) or newRpm > maxRpm) {
        throw std::invalid_argument("Invalid speed");
    }
    rpm = newRpm;
}

int Fan::getSpeed() {
    return rpm;
}
