#include "Controller.hpp"

Controller::Controller(IThermometer &slowThermometer,
                       Fan &fan,
                       double targetTemperature,
                       double tolerance,
                       std::shared_ptr<LcdDisplay> lcdDisplay) :
        thermometer(slowThermometer),
        fan(fan),
        lcdDisplay_(lcdDisplay),
        targetTemperature(targetTemperature),
        tolerance(tolerance) {
    if (tolerance < 0) {
        throw std::invalid_argument{"too low tolerance"};
    }

}

void Controller::updateRpm() {
    auto temp = thermometer.getTemperature();

    if (temp < (targetTemperature - tolerance))
        fan.setSpeed(0);
    else if (temp >= (targetTemperature - tolerance)
             && temp <= (targetTemperature + tolerance))
        fan.setSpeed(1000);
    else if (temp > (targetTemperature + tolerance + 2.0))
        fan.setSpeed(3000);
    else {
        int rpm =  (temp - targetTemperature - tolerance) * 1000;
        fan.setSpeed(rpm + 1000);

    }

}

