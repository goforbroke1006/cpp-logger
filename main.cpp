#include <iostream>

#include "Cat.h"

int main() {
    Logger_Info("Entry point");

    Cat c;

    Logger_Info("Cat is created");

    c.say();

    return 0;
}
