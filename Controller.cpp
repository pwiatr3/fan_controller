#include "Controller.hpp"

Controller::Controller(const Thermometer& thermometer,
                       Fan& fan,
                       double targetTemperature,
                       double tolerance,
                       std::shared_ptr<LcdDisplay> display) :
                            fan(fan), thermometer(thermometer), targetTemp(targetTemperature)
{}

void Controller::updateRpm() {
    auto currentTemp = thermometer.getTemperature();
    if (currentTemp == targetTemp)
        fan.setSpeed(1000);
    else if (currentTemp < targetTemp)
        fan.setSpeed(0);
    else if (currentTemp > targetTemp)
        fan.setSpeed(3000);
}

void Controller::displayInfo() {}
