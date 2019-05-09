#pragma once

class Fan {
    int rpm;

    Fan(const Fan&);  // copying not allowed
public:
    Fan();
    Fan(Fan&&);  // = default, broken Rule of 5
    void setSpeed(int newRpm);
    int getSpeed();  // missing const
};