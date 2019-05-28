#include "Controller.hpp"

Controller::Controller(const Thermometer& t,
                       Fan &f,
                       double temp,
                       double tol,
                       std::shared_ptr<LcdDisplay> disp_ptr):
                       t(t), f(f), temp(temp), tolerance(tol)
{}

void Controller::updateRpm() {
    if (t.getTemperature() < temp + tolerance && t.getTemperature() > temp - tolerance)
        f.setSpeed(1000);
    else
        f.setSpeed(0);
}

void Controller::displayInfo() {}
