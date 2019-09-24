#include "Controller.hpp"
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include "LcdDisplay.hpp"
#include <memory>
#include <iostream>

void fun(const std::shared_ptr<SlowThermometer>& p) {
    p->getTemperature();
    p.reset(new SlowThermometer);
}

int main()
try {
    // std::unique_ptr<SlowThermometer> up{new SlowThermometer(10.0)};
    auto up = std::make_shared<SlowThermometer>();
    fun(up);
    up->getTemperature();
    // auto temp = up->getTemperature();


    SlowThermometer t;
    Fan f;
    double targetTemperature = 36.6;
    double tolerance = .5;
    Controller oldController{t, f, targetTemperature, tolerance, nullptr};
    oldController.updateRpm();
    oldController.displayInfo();

    auto uptr = std::make_unique<LcdDisplay>();
    Controller newController{t, f, targetTemperature, tolerance, std::move(uptr)};
    newController.updateRpm();
    newController.displayInfo();
    uptr->print();

    return 0;
} catch (const std::exception & e) {
    std::cerr << e.what() << '\n';
    return -1;
}

