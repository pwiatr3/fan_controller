#include "external/catch.hpp"
#include "external/hippomocks.h"
#include "Controller.hpp"
#include "IThermometer.h"

class StubThermometer : public IThermometer {
public:
    double temperature{};

    double getTemperature() const {
        return temperature;
    }
};

TEST_CASE("Controller creation", "[Controller]") {

    StubThermometer t;
    Fan f;
    double targetTemperature = 36.6;
    double tolerance = .5;
    Controller controller{t, f, targetTemperature, tolerance};


//    SECTION("created fan is disabled") {
//        CHECK(f.getSpeed() == disabledRpm);
//    }


}

TEST_CASE("Controller test at 0 deg", "[Controller]") {

    SECTION("UpdateRPM") {
        GIVEN("A controller, fan, thermometer, targetTemperature = 0.0, tolerance = 1.0") {
            StubThermometer t;
            Fan f;
            double targetTemperature = 0.0;
            double tolerance = 1.0;
            Controller controller{t, f, targetTemperature, tolerance};

            WHEN("current temperature is between targetTemperature - tolerance and targetTemperature + tolerance") {
                auto values = { -1.0, -0.5, 0.0, 0.5, 1.0};
                for(auto it: values){
                    t.temperature = it;
                    controller.updateRpm();

                    THEN("Fan speed should be 1000 rpm") {
                        CHECK(f.getSpeed() == 1000);
                }

                }
            }

            WHEN("current temperature is between targetTemperature + tolerance and max") {
                std::vector<std::pair<double, int>> tempRpmPair =
                        {{1.0, 1000}, {1.5, 1500}, {2.0, 2000}, {2.5, 2500},{3, 3000}};


                for(auto it: tempRpmPair){
                    t.temperature = it.first;
                    controller.updateRpm();

                    THEN("Fan speed should be " << it.second << "rpm") {
                        CHECK(f.getSpeed() == it.second);
                    }

                }
            }

            WHEN("current temperature is 5.0") {
                t.temperature = 5.0;
                controller.updateRpm();

                THEN("Fan speed should be 3000 rpm") {
                    CHECK(f.getSpeed() == 3000);
                }


            }
            WHEN("current temperature is -5.0") {
                t.temperature = -5.0;
                controller.updateRpm();

                THEN("Fan speed should be 0 rpm") {
                    CHECK(f.getSpeed() == 0);
                }
            }

            WHEN("current temperature is 2") {
                t.temperature = 2.0;
                controller.updateRpm();

                THEN("Fan speed should be 2000 rpm") {
                    CHECK(f.getSpeed() == 2000);
                }
            }
        }

    }
    SECTION("NEGATIVE TOLERANCE TEST") {
        GIVEN("fan controller and termometer") {
            WHEN("tolerance is negative") {

                StubThermometer t;
                Fan f;
                double targetTemperature = 0.0;
                double tolerance = -1.0;
                std::unique_ptr<Controller> controller = nullptr;
                REQUIRE_THROWS_AS(controller.reset(new Controller{t, f, targetTemperature, tolerance}),
                                  std::invalid_argument);
            }
        }

    }
}