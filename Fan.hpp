#pragma once

class Fan {
    int rpm = 0;

public:
    virtual ~Fan() = default;

    virtual void setSpeed(int newRpm);
    int getSpeed() const;
};