#include "Logger.hpp"
#include "values.hpp"
#include "Algorithms.hpp"

void Algorithms::singleLoop() {
    START_TIMER();
    LOG_LOCATION("Running single loop");
    for (int i = 0; i < 1000; ++i) {
    }
    STOP_TIMER();
}

void Algorithms::doubleLoop() {  
    START_TIMER();
    LOG_LOCATION("Running double loop");
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {

        }
    }
    STOP_TIMER();
}

void Algorithms::tripleLoop() {
    START_TIMER();
    LOG_LOCATION("Running triple loop");
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            for (int k = 0; k < 1000; ++k) {

            }
        }
    }
    STOP_TIMER();
}