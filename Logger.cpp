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
}
