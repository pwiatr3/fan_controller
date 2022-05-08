#pragma once

class IFan {

public:
    virtual ~IFan() {};
    virtual void setSpeed(const int) = 0;
    virtual int getSpeed() const = 0;
    virtual bool disable() = 0;
    virtual bool enable() = 0;
};