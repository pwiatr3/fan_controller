#include "Controller.hpp"

Controller::Controller(IThermometer& t,
                       Fan& f,
                       double,
                       double,
                       std::shared_ptr<LcdDisplay>)
    : thermometer_{t}
    , fan_{f}
{}

void Controller::updateRpm() {
    if (thermometer_.getTemperature() < 0) {
        fan_.setSpeed(disabledSpeed);
    } else {
        fan_.setSpeed(maxSpeed);
    }
}

void Controller::displayInfo() {}
