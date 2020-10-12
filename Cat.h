

#ifndef CAT_H
#define CAT_H

#include <iostream>

#include "logger.h"

class Cat {
public:
    void say() {
        Logger_Info("Cat says meow");
        Logger_Warn("Cat says meow");
        Logger_Error("Cat says meow");
        try {
            Logger_Critical("Cat says meow");
        } catch (std::exception &ex) {
            // ignore
        }
        Logger_Fatal("Cat says meow");
        std::cout << "Meow!!!" << std::endl;
    }
};

#endif
