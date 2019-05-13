#pragma once
#include "Thermometer.hpp"
#include "Fan.hpp"
#include "LcdDisplay.hpp"
#include <memory>

class Controller {
    const Thermometer &thermometer;
    Fan &fan;
    std::shared_ptr<LcdDisplay> display;
    double targetTemperature;
    double tolerance;
    double recentTemperature;

public:
    Controller(const Thermometer &t,
               Fan &f,
               const double targetTemp,
               const double tolerance,
               std::shared_ptr<LcdDisplay> display);
    void updateRpm();
    void displayInfo() const;
};