#include "external/catch.hpp"
#include "Controller.hpp"
#include "Thermometer.h"

class StubThermometer : public Thermometer {
public:
    double temperature = 0.0;
    double getTemperature() const override {
        return temperature;
    }
};

SCENARIO("Controller - updateRpm() behavior", "[Controller]") {
    GIVEN("A Controller, StubThermometer, Fan, target temperature = 0.0, tolerance = 1.0") {
        StubThermometer t;
        Fan f;
        double targetTemperature = 0.0;
        double tolerance = 1.0;
        Controller controller{t, f, targetTemperature, tolerance};

        WHEN("Temperature is 0.0") {
            t.temperature = 0.0;
            controller.updateRpm();

            THEN("Fan speed is 1000") {
                CHECK(f.getSpeed() == 1000);
            }
        }

        WHEN("Temperature is -1.01") {
            t.temperature = -1.01;
            controller.updateRpm();

            THEN("Fan speed is 0") {
                CHECK(f.getSpeed() == 0);
            }
        }
    }

    GIVEN("A Controller, StubThermometer, Fan, target temperature = 100.0, tolerance = 0.0") {
        StubThermometer t;
        Fan f;
        double targetTemperature = 100.0;
        double tolerance = 0.0;
        Controller controller{t, f, targetTemperature, tolerance};

        WHEN("Temperature is 1000.0") {
            t.temperature = 1000.0;
            controller.updateRpm();

            THEN("Fan speed is 3000") {
                CHECK(f.getSpeed() == 3000);
            }
        }
    }
}
