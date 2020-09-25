#pragma once
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include <memory>
#include "IThermometer.hpp"

class LcdDisplay;

class Controller {
public:
    Controller(IThermometer&, Fan&, double temp, double tolerance, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
private:
    bool inMiddleRange(double value);
    bool inHigherRange(double value);

    IThermometer& thermometer_;
    Fan& fan_;
    double targetTemperature_;
    double tolerance_;
};
