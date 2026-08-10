#include "Logger.hpp"
TIME_POINT Logger::startTime = NOW;

void Logger::logLocation(const std::string message, const std::string &file, int line, const std::string &function)
{
    std::cout << "[LOG]" << file << ":" << line << " (" << function << ") - " << message << std::endl;
}

void Logger::startTimer()
{
}

void Logger::stopTimer(const std::string &function)
{
    auto endTime = NOW;  
    auto duration = DURATION(startTime, endTime);  
    std::cout << "[TIMER] (" << function << ") - Duration: " << duration << " µs" << std::endl;
}

void Logger::printCompileInfo()
{
    std::cout << "Date: " << __DATE__ << std::endl;
    std::cout << "Time: " << __TIME__ << std::endl;
    std::cout << "Compiler: ";
    #ifdef __GNUC__
        std::cout << "GCC " << __GNUC__ << "." << __GNUC_MINOR__ << std::endl;
    #elif defined(__clang__)
        std::cout << "Clang " << __clang_major__ << "." << __clang_minor__ << std::endl;
    #elif defined(_MSC_VER) 
        std::cout << "MSVC " << _MSC_VER << std::endl;
    #endif
    std::cout << PLATFORM << std::endl;
}
