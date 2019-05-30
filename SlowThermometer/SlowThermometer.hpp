#pragma once

#include "Thermometer.h"

class SlowThermometer : public Thermometer {
public:
    double getTemperature() const override;
};