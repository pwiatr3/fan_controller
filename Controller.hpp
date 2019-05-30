#pragma once
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include <memory>

class LcdDisplay;

class Controller {
public:
    Controller(const Thermometer&, Fan&, double, double, std::shared_ptr<LcdDisplay> = nullptr);
    void updateRpm();
    void displayInfo();
private:
    const Thermometer& thermometer;
    Fan& fan;
    double targetTemp;
};