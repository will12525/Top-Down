#include "controller.h"



int main(int argc, char** argv) {
    Controller* c = Controller::getInstance();
    c->loop();
    return 0;
}
