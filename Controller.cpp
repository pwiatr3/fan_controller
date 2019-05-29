#include "Controller.hpp"

Controller::Controller(Thermometer const &thermometer,
                       Fan &fan,
                       double temperature,
                       double tolerance,
                       std::shared_ptr<LcdDisplay> display)
    : thermometer(thermometer)
    , fan(fan)
    , temperature(temperature)
    , tolerance(tolerance)
    , display(display)
{}

void Controller::updateRpm() {
    if(temperature - tolerance > thermometer.getTemperature()) {
        fan.setSpeed(0);
    }
    else if(temperature + tolerance < thermometer.getTemperature()) {
        fan.setSpeed(3000);
    }
    else {
        fan.setSpeed(1000);
    }
}

void Controller::displayInfo() {}
