#include "external/catch.hpp"
#include "external/hippomocks.h"
#include "Controller.hpp"
#include "Thermometer.hpp"
#include "Fan.hpp"

constexpr double TARGET_TEMP = 100.0;
constexpr double TOLERANCE = 10.0;

struct StubThermometer : Thermometer {
    double temperature = TARGET_TEMP;

    double getTemperature() const override {
        return temperature;
    }
};

MockRepository mocks;

SCENARIO("Controller's behavior", "[Controller]") {
    GIVEN("A Controller with a StubThermometer and a MockFan") {
        Fan *fanMock = mocks.Mock<Fan>();
        StubThermometer st;
        Controller c{st, *fanMock, TARGET_TEMP, TOLERANCE, nullptr};

        WHEN("Temperature is target temperature") {
            st.temperature = TARGET_TEMP;
            THEN("Fan speed is 1000 rpm") {
                mocks.ExpectCall(fanMock, Fan::setSpeed).With(1000);
                c.updateRpm();
            }
        }
        WHEN("Temperature is below target - tolerance") {
            st.temperature = TARGET_TEMP - TOLERANCE - 0.01;
            THEN("Fan should be stopped") {
                mocks.ExpectCall(fanMock, Fan::setSpeed).With(0);
                c.updateRpm();
            }
        }
        WHEN("Temperature is above target + tolerance + 2") {
            st.temperature = TARGET_TEMP + TOLERANCE + 42;
            THEN("Fan speed is 3000 rpm") {
                mocks.ExpectCall(fanMock, Fan::setSpeed).With(3000);
                c.updateRpm();
            }
        }
    }
}

SCENARIO("Controller - updateRpm() behavior", "[Controller]") {
    GIVEN("A Controller, StubThermometer, Fan, target temperature = 0.0, tolerance = 1.0") {
        Fan fan;
        StubThermometer st;
        auto tolerance = 1.0;
        Controller c{st, fan, 0.0, tolerance, nullptr};
        REQUIRE(fan.getSpeed() == 0);

        WHEN("Temperature is -1.01") {
            st.temperature = -1.01;
            c.updateRpm();

            THEN("Fan speed is 0") {
                CHECK(fan.getSpeed() == 0);
            }
        }

        WHEN("Temperature is -1.0") {
            st.temperature = -1.0;
            c.updateRpm();

            THEN("Fan speed is 1000") {
                CHECK(fan.getSpeed() == 1000);
            }
        }

        WHEN("Temperature is 1.0") {
            st.temperature = 1.0;
            c.updateRpm();

            THEN("Fan speed is 1000") {
                CHECK(fan.getSpeed() == 1000);
            }
        }

        WHEN("Temperature is 1.1") {
            st.temperature = 1.1;
            c.updateRpm();
            THEN("Fan speed is 1100 rpm") {
                CHECK(fan.getSpeed() == 1100);
            }
        }

        WHEN("Temperature is 3.0") {
            st.temperature = 3.0;
            c.updateRpm();
            THEN("Fan speed is 3000 rpm") {
                CHECK(fan.getSpeed() == 3000);
            }
        }

        WHEN("Temperature is 5.0") {
            st.temperature = 5.0;
            c.updateRpm();
            THEN("Fan speed is 3000 rpm") {
                CHECK(fan.getSpeed() == 3000);
            }
        }

        WHEN("Temperature is -2.0") {
            st.temperature = -2.0;
            c.updateRpm();
            THEN("Fan speed is 0 rpm") {
                CHECK(fan.getSpeed() == 0);
            }
        }

        WHEN("Temperature is 0.5") {
            st.temperature = 0.5;
            c.updateRpm();
            THEN("Fan speed is 1000 rpm") {
                CHECK(fan.getSpeed() == 1000);
            }
        }
    }
}

SCENARIO("Controller - creation", "[Controller]") {
    GIVEN("Tolerance = -1.0") {
        double tolerance = -1.0;
        Fan fan;
        std::unique_ptr<Controller> c = nullptr;

        WHEN("A controller is created") {
            THEN("Logic_error is raised") {
                REQUIRE_THROWS_AS(c.reset(new Controller{StubThermometer{}, fan, 0.0, tolerance, nullptr}),
                        std::logic_error);
            }
        }
    }
}

SCENARIO("Controller - displayInfo() behavior", "[Controller]") {
    GIVEN("A controller with a display") {
        Fan fan;
        StubThermometer st;
        LcdDisplay *rawDisplay = mocks.Mock<LcdDisplay>();
        auto display = std::shared_ptr<LcdDisplay>{rawDisplay, [](LcdDisplay*){}};
        auto targetTemperature = 42.0;
        st.temperature = targetTemperature + 1.0;
        Controller c{st, fan, targetTemperature, 0.5, display};


        WHEN("An updateRpm() and displayInfo() are called") {
            c.updateRpm();

            THEN("It provides an expected string") {
                std::stringstream expectedOutput;
                expectedOutput << "Target temp: " << targetTemperature << '\n'
                            << "Current temp: " << st.temperature << '\n'
                            << "Fan speed: " << fan.getSpeed() << '\n';
            
                mocks.ExpectCall(rawDisplay, LcdDisplay::print).With(expectedOutput.str());
                c.displayInfo();
            }
        }
    }
}