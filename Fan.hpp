#pragma once

class Fan {
    int rpm = 0;

public:
    Fan();
    void setSpeed(int newRpm);
    int getSpeed() const;
};