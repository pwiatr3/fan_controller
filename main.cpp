#include "Controller.hpp"
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include "LcdDisplay.hpp"
#include <memory>
#include <iostream>

int main()
try {
    SlowThermometer t;
    Fan f;
    LcdDisplay lcdDisplay;
    double targetTemperature = 36.6;
    double tolerance = .5;
    Controller controller{t, f, targetTemperature, tolerance};
    controller.updateRpm();

    return 0;
} catch (const std::exception & e) {
    std::cerr << e.what() << '\n';
    return -1;
}

