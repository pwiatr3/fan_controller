#include "Controller.hpp"
#include <memory>

int main() {
    Termomether t;
    Fan f;
    Controller c{t, std::move(f), 36.6};
    c.run();

    c.stop();

    Controller newController{t, std::move(f), 36.6};  // use after move
    newController.run();

    newController.stop();
    return 0;
}