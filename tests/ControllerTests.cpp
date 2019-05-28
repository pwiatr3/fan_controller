#include "external/catch.hpp"
#include "Controller.hpp"


SCENARIO("Controller - updateRpm() behavior", "[Controller]") {
    GIVEN("A Controller, StubThermometer, Fan, target temperature = 0.0, tolerance = 1.0") {

        WHEN("Temperature is 0.0") {
            THEN("Fan speed is 1000") {
            }
        }

        WHEN("Temperature is -1.01") {
            THEN("Fan speed is 0") {
            }
        }

    }
}
