#include "Controller.hpp"

Controller::Controller(IThermometer&,
                       IFan&,
                       double,
                       double,
                       const std::shared_ptr<LcdDisplay>&)
{}

void Controller::updateRpm() {}

void Controller::displayInfo() {}
