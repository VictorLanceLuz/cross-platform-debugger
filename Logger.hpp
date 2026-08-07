#include "values.hpp"
#include <iostream>
#include <string>
#include <chrono>

class Logger {
    private:
    public:
        static void logLocation(const std::string message,
                                const std::string& file,
                                int line,
                                const std::string & function);
        static void startTimer();
        static void stopTimer(const std::string& function);
        static void printCompileInfo();
};

// Macros for easy usage
#define LOG_LOCATION(msg) Logger::logLocation(msg, __FILE__, __LINE__, __FUNCTION__)