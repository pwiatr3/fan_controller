#include "external/catch.hpp"
#include "Controller.hpp"
#include "StubThermometer.h"

SCENARIO("Controller - updateRpm() behavior", "[Controller]") {
    GIVEN("A Controller, StubThermometer, Fan, target temperature = 0.0, tolerance = 1.0") {
        Fan f;
        StubThermometer st;
        double targetTemperature = 0.0;
        double tolerance = 1.0;
        Controller controller{st, f, targetTemperature, tolerance, nullptr};

        WHEN("Temperature is 0.0") {
            st.temperature = 0.0;
            controller.updateRpm();

            THEN("Fan speed is 1000") {
                CHECK(f.getSpeed() == 1000);
            }
        }

        WHEN("Temperature is -1.01") {
            st.temperature = -1.01;
            controller.updateRpm();

            THEN("Fan speed is 0") {
                CHECK(f.getSpeed() == 0);
            }
        }

        WHEN("Temperature is 100") {
            st.temperature = 100.0;
            controller.updateRpm();

            THEN("Fan speed is 3000") {
                CHECK(f.getSpeed() == 3000);
            }
        }

    }
}
