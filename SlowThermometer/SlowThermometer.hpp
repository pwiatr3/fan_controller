#pragma once
#include "IThermometer.h"
class SlowThermometer : public IThermometer{
public:
    double getTemperature() const override;
};