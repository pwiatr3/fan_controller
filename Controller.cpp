#include "Controller.hpp"
#include "LcdDisplay.hpp"

Controller::Controller(const IThermometer& t,
                       Fan& f,
                       double targetTemperature,
                       double tolerance,
                       std::unique_ptr<LcdDisplay> lcd):
                    thermometer_(t),
                    fan_(f), 
                    targetTemperature_(targetTemperature), 
                    tolerance_(tolerance),
                    lcd_(std::move(lcd))
{}

void Controller::updateRpm() {
    double currentTemperature = thermometer_.getTemperature();
    if(currentTemperature < (targetTemperature_ - tolerance_))
        fan_.setSpeed(0);
    else if(currentTemperature >= (targetTemperature_ - tolerance_) and
            currentTemperature <= (targetTemperature_ + tolerance_))
        fan_.setSpeed(1000);
    else 
        fan_.setSpeed(2000);
}

void Controller::displayInfo() {}
