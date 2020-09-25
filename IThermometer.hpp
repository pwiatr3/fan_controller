#pragma once

struct IThermometer {
//public:
    //IThermometer()
    virtual ~IThermometer() = default;
    virtual double getTemperature() const = 0;
};