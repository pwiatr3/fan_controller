#include "Controller.hpp"
#include <memory>

Controller::Controller(Termomether t, Fan f, double targetTemp)
    : termomether(t)
    , fan(std::move(f))
    , targetTemperature(targetTemp)
     {}

Controller::~Controller() {
    // do not let to cut off the power when temp is above 37
    // if so, set fan speed to max and wait for 10 seconds
}

void Controller::run() {}

void Controller::stop() {}