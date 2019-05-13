#pragma once

class Thermometer {
public:
    virtual ~Thermometer() = default;
    
    virtual double getTemperature() const = 0;
};