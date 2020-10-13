//
// Created by scherkesov on 11.10.2020.
//

#ifndef GFB_LOGGER_H
#define GFB_LOGGER_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <ctime>

#ifdef _WIN32

#include <Windows.h>


#define COLOR_TEXT_RED      12
#define COLOR_TEXT_GREEN    10
#define COLOR_TEXT_YELLOW   14
#define COLOR_TEXT_MAGENTA  13

#else

#define COLOR_TEXT_RED      31
#define COLOR_TEXT_GREEN    32
#define COLOR_TEXT_YELLOW   33
#define COLOR_TEXT_MAGENTA  35

#endif

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


    static void print(
            const int colorCode,
            const std::string &levelLabel,
            char const *function, char const *file, long line,
            const std::string &message
    ) {


#ifdef _WIN32

#if defined(_DEBUG)
        std::string text =
                "[" + levelLabel + "] - " + getDateTime() + " - "
                + message + " at " + file + ":" + std::to_string(line) + " " + function;
        OutputDebugStringA(text.c_str());
#else
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, colorCode);
        std::cout
                << "[" << levelLabel << "] - " << message;

        SetConsoleTextAttribute(hConsole, 0);
        std::cout
                << " at " << file << ":" << line << " " << function
                << std::endl;
#endif

#else
        std::cout
                << "\033[" << colorCode << "m"
                << "[" << levelLabel << "] - " << getDateTime() << " - " << message
                << "\033[0m"
                << " at " << file << ":" << line << " " << function
                << std::endl;
#endif
    }

private:
    static std::string getDateTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t start_time = std::chrono::system_clock::to_time_t(now);
        auto buf = std::localtime(&start_time);
        char timedisplay[100];
        size_t len = std::strftime(timedisplay, sizeof(timedisplay), "%Y-%m-%d %H:%M:%S", buf);
//        size_t len = std::strftime(timedisplay, sizeof(timedisplay), "%H:%M:%S", buf);
        return std::string(timedisplay, len);
    }
};

#ifdef __GNUC__

#define Logger_Info(message)        Logger::print(COLOR_TEXT_GREEN, "INFO", __PRETTY_FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Warn(message)        Logger::print(COLOR_TEXT_YELLOW, "WARNING", __PRETTY_FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Error(message)       Logger::print(COLOR_TEXT_MAGENTA, "ERROR", __PRETTY_FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Critical(message)    Logger::critical(__PRETTY_FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Fatal(message)       Logger::fatal(__PRETTY_FUNCTION__, __FILE__, __LINE__, (message));

#else

#define Logger_Info(message)        Logger::print(COLOR_TEXT_GREEN, "INFO", __FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Warn(message)        Logger::print(COLOR_TEXT_YELLOW, "WARNING", __FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Error(message)       Logger::print(COLOR_TEXT_MAGENTA, "ERROR", __FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Critical(message)    Logger::critical(__FUNCTION__, __FILE__, __LINE__, (message));
#define Logger_Fatal(message)       Logger::fatal(__FUNCTION__, __FILE__, __LINE__, (message));

#endif

#endif //CPP_LOGGER_LOGGER_H
