#include "Controller.hpp"
#include <memory>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stdexcept>

Controller::Controller(
        const Thermometer &t,
        Fan &f,
        const double targetTemp,
        const double tolerance,
        std::shared_ptr<LcdDisplay> display)
    : thermometer(t)
    , fan(f)
    , display(std::move(display))
    , targetTemperature(targetTemp)
    , tolerance(tolerance)
    , recentTemperature(0)
{
    if (tolerance < 0.0) {
        throw std::logic_error("Tolerance cannot be negative");
    }
}

void Controller::updateRpm() {
    recentTemperature = thermometer.getTemperature();
    auto difference = recentTemperature - targetTemperature;
    if (difference < -tolerance) {
        fan.setSpeed(0);
    } else if (difference <= 0) {
        fan.setSpeed(1000);
    } else {
        int newRpm = 1000 + (difference - tolerance) * 1000;
        int newSpeed = std::min(std::max(newRpm, 1000), 3000);  // std::clamp in C++17
        fan.setSpeed(newSpeed);
    }
}

void Controller::displayInfo() const {
    if (display) {
        std::stringstream msg;
        msg << "Target temp: " << targetTemperature << '\n'
            << "Current temp: " << recentTemperature << '\n'
            << "Fan speed: " << fan.getSpeed() << '\n';
         display->print(msg.str());
    }
}