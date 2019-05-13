#pragma once
#include "Thermometer.hpp"

class SlowThermometer : public Thermometer {
public:
    double getTemperature() const override;
};