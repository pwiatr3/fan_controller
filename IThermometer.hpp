#pragma once

class IThermometer {
public:
    virtual ~IThermometer();
    virtual double getTemperature() const;
};