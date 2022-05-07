#pragma once
#include "IThermometer.hpp"
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include "IFan.hpp"
#include <memory>

class LcdDisplay;

class Controller {
public:
    Controller(IThermometer&, IFan& , double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
};