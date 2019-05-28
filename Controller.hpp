#pragma once
#include "Thermometer.h"
#include "Fan.hpp"
#include <memory>

class LcdDisplay;

class Controller {
public:
    Controller(const Thermometer&, Fan&, double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
private:
    const Thermometer& t;
    Fan& f;
    double temp;
    double tolerance;
};