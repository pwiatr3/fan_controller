#pragma once
#include "Fan.hpp"
#include <memory>
#include "Thermometer.h"

class LcdDisplay;

class Controller {
    Thermometer const &thermometer;
    Fan &fan;
    double temperature;
    double tolerance;
    std::shared_ptr<LcdDisplay> display;
public:
    Controller(Thermometer const & , Fan&, double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
};