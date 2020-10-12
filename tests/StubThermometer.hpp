#pragma once
#include "IThermometer.hpp"

class StubThermometer : public IThermometer {
public:
    double temperature {};
    double getTemperature() const override {
        return temperature;
    }
};
