#include "external/catch.hpp"
#include "Controller.hpp"
#include "Thermometer.h"

class StubThermometer final : public Thermometer {
public:
    double temperature = 0.0;

    double getTemperature() const override {
        return temperature;
    }
};

SCENARIO("Controller - updateRpm() behavior", "[Controller]") {
    GIVEN("A Controller, StubThermometer, Fan, target temperature = 0.0, tolerance = 1.0") {

        StubThermometer myThermometer;
        Fan myFan;
        double temperature = 0.0;
        double tolerance = 1.0;

        Controller myController(myThermometer, myFan, temperature, tolerance, nullptr);

        WHEN("Temperature is 0.0") {
            myThermometer.temperature = 0.0;
            myController.updateRpm();
            THEN("Fan speed is 1000") {

                CHECK(myFan.getSpeed() == 1000);
            }
        }

        WHEN("Temperature is -1.01") {
            myThermometer.temperature = -1.01;
            myController.updateRpm();
            THEN("Fan speed is 0") {
            }
        }

    }
}
