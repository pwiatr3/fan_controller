#pragma once

class Thermometer {
public:
    virtual double getTemperature() const = 0;
    virtual ~Thermometer() = default;
};