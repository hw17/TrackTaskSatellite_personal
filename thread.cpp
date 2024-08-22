
#include <thread>
#include <mutex>

#include "time.h"
#include "mythread.h"

// Mutex to threads synchronize
std::mutex mtx;
std::vector<std::string> recentValues(3);

//Function to get the most recent value from socket
void thread_readValues(TCPClient argClient, int socketNum){
    while (true) {
        // Reading from the socket
        std::string value = argClient.sreadValue();

        // Update recentValues vector, lock to avoid corruption in data
        std::lock_guard<std::mutex> lock(mtx);
        recentValues[socketNum - 1] = value;
    }
}

void thread_printValues(void){
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Lock to avoid corruption in data while printing
        std::lock_guard<std::mutex> lock(mtx);
        auto timestamp = currentTimeMillis();

        std::cout << "{\"timestamp\": " << timestamp;

        // Check if values are present for each socket
        for (size_t i = 0; i < recentValues.size(); ++i) {
            if (!recentValues[i].empty()) {
                std::cout << ", \"out" << (i + 1) << "\": \"" << recentValues[i] << "\"";
            } else {
                // No value received
                std::cout << ", \"out" << (i + 1) << "\": \"--\"";
            }
        }
        std::cout << "}," << std::endl;
    }
}

//int main(){
    // std::thread t1(thread1_r);
    // std::thread t2(thread2_r);
    // std::thread t3(thread3_r);
    // if (t1.joinable()) t1.join();
    // if (t2.joinable()) t2.join();
    // if (t3.joinable()) t3.join();
    // if (t4.joinable()) t4.join();
    // return 0;
//}

