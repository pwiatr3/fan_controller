#pragma once
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include <memory>

class LcdDisplay;

class Controller {
    IThermometer & thermometer;
    Fan & fan;

    std::shared_ptr<LcdDisplay> lcdDisplay_;
    double targetTemperature;
    double tolerance;
public:
    Controller(IThermometer &, Fan &, double targetTemperature, double tolerance, std::shared_ptr<LcdDisplay> lcdDisplay = nullptr);
    void updateRpm();
};