#include "external/catch.hpp"
#include "external/hippomocks.h"
#include "Controller.hpp"
#include "MockThermometer.hpp"


TEST_CASE("Controller - setSpeed() behavior", "[Controller]") {

    Fan f {};
    MockThermometer st;
    constexpr int disabledRpm = 0;
    constexpr int minRpm = 1000;
    constexpr int maxRpm = 3000;

    constexpr double targetTemperature = 36.6;
    constexpr double tolerance = .5;
    Controller c{st, f, targetTemperature, tolerance, nullptr};
    // oldController.updateRpm();
    // oldController.displayInfo();

    SECTION("is update of speed working for 0 C") {
        CHECK(f.getSpeed() == disabledRpm);
    }

    SECTION("Given temperature target fan controller should set rpm to 1000 ") {
        st.setTemperature(targetTemperature);
        c.updateRpm();
        CHECK(f.getSpeed() == minRpm);
    }

     SECTION("Given temperature range fan controller should set rpm to 1000 ") {
        st.setTemperature(targetTemperature - tolerance);
        c.updateRpm();
        CHECK(f.getSpeed() == minRpm);
    }

     SECTION("Given temperature below temp-tolerance fan controller should set rpm to 0") {
        st.setTemperature(targetTemperature - tolerance -1);
        c.updateRpm();
        CHECK(f.getSpeed() == disabledRpm);
    }

    SECTION("Given temperature below temp-tolerance fan controller should set rpm to 0") {
        int beforeSpeed = f.getSpeed();
        st.setTemperature(targetTemperature + tolerance + 2);
        c.updateRpm();
        CHECK(f.getSpeed() == 2000);
    }


    // SECTION("setting proper values") {
    //     c.setSpeed(minRpm);
    //     CHECK(c.getSpeed() == minRpm);

    //     c.setSpeed(maxRpm);
    //     CHECK(c.getSpeed() == maxRpm);

    //     c.setSpeed(disabledRpm);
    //     CHECK(c.getSpeed() == disabledRpm);
    // }

    // SECTION("setting invalid values") {
    //     auto before = c.getSpeed();

    //     REQUIRE_THROWS_AS(c.setSpeed(minRpm - 1), std::invalid_argument);
    //     CHECK(c.getSpeed() == before);

    //     REQUIRE_THROWS_AS(c.setSpeed(maxRpm + 1), std::invalid_argument);
    //     CHECK(c.getSpeed() == before);
    // }
}