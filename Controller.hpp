#pragma once
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include <memory>

class LcdDisplay;

class Controller {
public:
    Controller(SlowThermometer, Fan, double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
private:
    SlowThermometer slowThermometer_;
    Fan fan_;
    double targetTemperature_;
    double tolerance_;
};
