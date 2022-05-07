#include "Controller.hpp"

Controller::Controller(IThermometer&,
                       IFan&,
                       double,
                       double,
                       std::shared_ptr<LcdDisplay>)
{}

void Controller::updateRpm() {}

void Controller::displayInfo() {}
