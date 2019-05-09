#include "Termomether.hpp"
#include <random>

Termomether::Termomether() {}  // c-tor not needed

double Termomether::getTemperature()   // how to test random values? move to class, give a seed
{
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{36.6, 2.0};
    return d(gen);
}