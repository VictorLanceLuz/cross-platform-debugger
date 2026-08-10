#ifdef _WIN32
    #define PLATFORM "Windows"
#elif defined(__linux__)
    #define PLATFORM "Linux"
#elif defined(__APPLE__)
    #define PLATFORM "macOS" 
#else
    #define PLATFORM "Unsupported platform"
    #error ("This platform is not supported.")
#endif

#include <chrono>
#define TIME_POINT std::chrono::high_resolution_clock::time_point
#define NOW std::chrono::high_resolution_clock::now()
#define DURATION(start, end) std::chrono::duration_cast<std::chrono::microseconds>((end) - (start)).count()
#define DEBUG_MODE