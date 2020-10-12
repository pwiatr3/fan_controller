#pragma once

constexpr int maxSpeed = 3000;
constexpr int disabledSpeed = 0;

class Fan {
    int rpm = 0;

public:
    void setSpeed(int newRpm);
    int getSpeed() const;
};