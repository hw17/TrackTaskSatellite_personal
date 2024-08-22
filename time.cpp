#include <chrono>

#include "time.h"

// Function to get the current time in milliseconds since the Unix epoch
long long currentTimeMillis(void) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count(); //get EPOCH time
}
