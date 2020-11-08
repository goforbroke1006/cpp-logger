#include <iostream>

#include "Cat.h"

int main() {
    CppLogger::registerTarget(
            new FileLoggerTarget("./cpp-logger-all.log", LOG_LEVEL_DEBUG)
    );

    Logger_Info("Entry point");

    Cat c;

    Logger_Info("Cat is created");

    c.say();

    return 0;
}
