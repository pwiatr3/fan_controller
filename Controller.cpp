#include <algorithm>
#include <cmath>

#include "Controller.hpp"

constexpr int kMaxspeed = 3000;

Controller::Controller(IThermometer& thermo,
                       Fan& f,
                       double temp,
                       double tolerance,
                       std::shared_ptr<LcdDisplay>)
    : thermometer_(thermo), fan_(f), targetTemperature_(temp), tolerance_(tolerance) {}

bool Controller::inMiddleRange(double value) {
    return value >= (targetTemperature_ - tolerance_) && value <= (targetTemperature_ + tolerance_);
}

bool Controller::inHigherRange(double value) {
    return value > (targetTemperature_ + tolerance_);
}

void Controller::updateRpm() {
    double actualTemp = thermometer_.getTemperature();
    if (inMiddleRange(actualTemp)) {
        fan_.setSpeed(1000);
    } else if (inHigherRange(actualTemp)) {
        double temperatureDifference = std::abs(actualTemp - targetTemperature_ + tolerance_);
        int newSpeed = std::min(kMaxspeed,
                                static_cast<int>(temperatureDifference * 1000) + fan_.getSpeed());
        fan_.setSpeed(newSpeed);
    } else {
        fan_.disable();
    }
}

void Controller::displayInfo() {}
