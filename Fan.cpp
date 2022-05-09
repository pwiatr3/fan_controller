#include "Fan.hpp"
#include <stdexcept>
#include <cmath>

void Fan::setSpeed(const int newRpm) {
    if ((newRpm < minRpm and newRpm != 0) or newRpm > maxRpm) {
        throw std::invalid_argument("Invalid speed");
    }
    auto difference = std::abs(newRpm - rpm);
    for (auto i = 0; i < difference; ++i) {
        if (newRpm - rpm > 0) {
            rpm++;
        } else {
            rpm--;
        }
    }
}

int Fan::getSpeed() const {
    return rpm;
}

bool Fan::disable() {
    rpm = 0;
    return true;
}

bool Fan::enable() {
    rpm = minRpm;
    return true;
}
