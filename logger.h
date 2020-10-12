//
// Created by scherkesov on 11.10.2020.
//

#ifndef GFB_LOGGER_H
#define GFB_LOGGER_H

#include <iostream>
#include <stdexcept>

#define COLOR_TEXT_RED      31
#define COLOR_TEXT_GREEN    32
#define COLOR_TEXT_YELLOW   33
#define COLOR_TEXT_MAGENTA  35

class Logger {
public:

    static void critical(char const *function, char const *file, long line, const std::string &message) {
        print(COLOR_TEXT_RED, "CRITICAL", function, file, line, message);
        throw std::runtime_error(message);
    }

    static void fatal(char const *function, char const *file, long line, const std::string &message) {
        print(COLOR_TEXT_RED, "FATAL", function, file, line, message);
        exit(EXIT_FAILURE);
    }


    inline static void print(
            const int colorCode,
            const std::string &levelLabel,
            char const *function, char const *file, long line,
            const std::string &message
    ) {
        std::cout << "\033[" << colorCode << "m"
                  << "[" << levelLabel << "] - " << message
                  << "\033[0m"
                  << " at " << file << ":" << line << " " << function
                  << std::endl;
    }
};

#define Logger_Info(message)        Logger::print(COLOR_TEXT_GREEN, "INFO", __PRETTY_FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Warn(message)        Logger::print(COLOR_TEXT_YELLOW, "WARNING", __PRETTY_FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Error(message)       Logger::print(COLOR_TEXT_MAGENTA, "ERROR", __PRETTY_FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Critical(message)    Logger::critical(__PRETTY_FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Fatal(message)       Logger::fatal(__PRETTY_FUNCTION__, __FILE__, __LINE__, (message));

#endif //CPP_LOGGER_LOGGER_H
