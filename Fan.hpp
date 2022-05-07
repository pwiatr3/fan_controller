#pragma once

#include "IFan.hpp"

constexpr int minRpm = 1000;
constexpr int maxRpm = 3000;

class Fan : public IFan {
    int rpm = 0;

public:
    Fan();
    Fan(const Fan&);
    Fan(Fan&&);

    void setSpeed(int newRpm) override;
    int getSpeed() override;
    bool disable() override;
    bool enable() override;
};