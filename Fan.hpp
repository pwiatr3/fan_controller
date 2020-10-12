#pragma once

class Fan {
    int rpm = 0;

public:
    void setSpeed(int newRpm);
    int getSpeed() const;
};