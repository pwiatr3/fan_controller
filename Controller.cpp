#include "Controller.hpp"

Controller::Controller(IThermometer&,
                       Fan,
                       double,
                       double,
                       std::shared_ptr<LcdDisplay>)
{}

void Controller::updateRpm() {}

void Controller::displayInfo() {}
