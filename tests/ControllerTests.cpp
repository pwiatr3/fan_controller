#include "external/catch.hpp"
#include "external/hippomocks.h"
#include "Controller.hpp"
#include "../IThermometer.hpp"
#include "LcdDisplay.hpp"

class StubThermometer : public IThermometer{
public:
    StubThermometer(double temperature) : temperature_(temperature) {}
    double getTemperature() const override 
    {
        return temperature_;
    };

private:
    double temperature_;
};

Fan f;


SCENARIO("Fan controller") {
    GIVEN("Thermometer, Fan, Controller, target temp = 100, tolerance = 1, current temp = 0") {
        StubThermometer t(0.0);
        double targetTemperature = 100.0;
        double tolerance = 1.0;
        t.getTemperature();
        Controller cut(t, f, targetTemperature, tolerance, nullptr);

        WHEN("updateRmp is called") {
            cut.updateRpm();

            THEN("fan rmp = 0") {
                CHECK(f.getSpeed() == 0);
            }
        }
    }
    GIVEN("Thermometer, Fan, Controller, target temp = 100, tolerance = 1, current temp = 99") {
        StubThermometer t(99.0);
        double targetTemperature = 100.0;
        double tolerance = 1.0;
        t.getTemperature();
        Controller cut(t, f, targetTemperature, tolerance, nullptr);

        WHEN("updateRmp is called") {
            cut.updateRpm();

            THEN("fan rmp = 1000") {
                CHECK(f.getSpeed() == 1000);
            }
        }
    }
    GIVEN("Thermometer, Fan, Controller, target temp = 100, tolerance = 1, current temp = 100") {
        StubThermometer t(100.0);
        double targetTemperature = 100.0;
        double tolerance = 1.0;
        t.getTemperature();
        Controller cut(t, f, targetTemperature, tolerance, nullptr);

        WHEN("updateRmp is called") {
            cut.updateRpm();

            THEN("fan rmp = 1000") {
                CHECK(f.getSpeed() == 1000);
            }
        }
    }
    GIVEN("Thermometer, Fan, Controller, target temp = -100, tolerance = 1, current temp = -99") {
        StubThermometer t(-99.0);
        double targetTemperature = -100.0;
        double tolerance = 1.0;
        t.getTemperature();
        Controller cut(t, f, targetTemperature, tolerance, nullptr);

        WHEN("updateRmp is called") {
            cut.updateRpm();

            THEN("fan rmp = 1000") {
                CHECK(f.getSpeed() == 1000);
            }
        }
    }
    GIVEN("Thermometer, Fan, Controller, target temp = -100, tolerance = 1, current temp = -98") {
        StubThermometer t(-98.0);
        double targetTemperature = -100.0;
        double tolerance = 1.0;
        t.getTemperature();
        Controller cut(t, f, targetTemperature, tolerance, nullptr);

        WHEN("updateRmp is called") {
            cut.updateRpm();

            THEN("fan rmp = 1000") {
                CHECK(f.getSpeed() == 2000);
            }
        }
    }
}

// SCENARIO("parametrized") {
//     struct testData {
//         double targetTemperature;
//         double tolerance;
//         double currentTemperature;
//         int fanSpeed;
//     };
//     auto s = GENERATE(as<std::string>{},
//         {-100.0, 1.0, -98.0, 2000},
//         {100.0, 1.0, 0.0, 0},
//     );

//     GIVEN("Thermometer, Fan, Controller, target temp = " + s.targetTemperature ", tolerance = 1, current temp = -98") {
//         StubThermometer t(s.currentTemperature);
//         double targetTemperature = s.targetTemperature;
//         double tolerance = s.tolerance;
//         t.getTemperature();
//         Controller cut(t, f, targetTemperature, tolerance, nullptr);

//         WHEN("updateRmp is called") {
//             cut.updateRpm();

//             THEN("fan rmp = 1000") {
//                 CHECK(f.getSpeed() == s.fanSpeed);
//             }
//         }
//     }
// }