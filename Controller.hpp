#pragma once
#include "Termomether.hpp"
#include "Fan.hpp"

class Controller {
    Termomether termomether;  // OOD - it should read thermometer value periodicaly and setSpeed
    Fan fan;
    double targetTemperature;
    bool running;

    Controller(const Controller&);  // missing copy assignment operator
public:
    Controller(Termomether t, Fan f, double targetTemp);
    ~Controller();
    void setSpeed(int rpm);
    int getSpeed() const; // non-const getter
    void run();
    void stop();
};