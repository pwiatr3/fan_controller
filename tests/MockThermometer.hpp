#pragma once

#include "IThermometer.hpp"

class MockThermometer : public IThermometer {
public:
    double getTemperature() const{
        return 5;
    }
};
