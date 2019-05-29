#pragma once
#include "Thermometer.h"

class StubThermometer : public Thermometer {
public:

    double temperature = 0.0;
    double getTemperature() const override;

};

