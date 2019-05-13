#pragma once
#include <string>

class LcdDisplay {
public:
    virtual ~LcdDisplay() = default;
    virtual void print(std::string message) const;
};