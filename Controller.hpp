#pragma once
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include "IThermometer.hpp"
#include <memory>

class LcdDisplay;

class Controller {
public:
    Controller() = default;
    Controller(const IThermometer&, Fan&, double, double, std::unique_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
private:
    const IThermometer& thermometer_;
    Fan& fan_;
    double targetTemperature_;
    double tolerance_;
    std::unique_ptr<LcdDisplay> lcd_;
};