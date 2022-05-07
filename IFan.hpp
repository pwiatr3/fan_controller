#pragma once

class IFan {

public:
    virtual ~IFan() {};
    virtual void setSpeed(int) = 0;
    virtual int getSpeed() = 0;
    virtual bool disable() = 0;
    virtual bool enable() = 0;
};