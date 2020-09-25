#pragma once

#include "IThermometer.hpp"

class MockThermometer : public IThermometer {
protected:
    double tmp_{};

public:
    double getTemperature() const{
        return tmp_;
    }

    void setTemperature(double tmp) {
        tmp_ = tmp;
    }
};
