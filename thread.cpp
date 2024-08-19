#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <ctime>

#include "mythread.h"

// 0.1 seconds for time waster.
constexpr std::chrono::duration<int, std::micro> ms100(100000);

// thread task loop 
void taskloop()
{
    // just 10 iterations. Replace with proper termination condition
    for (int count = 0; count < 10; count++) 
    {
        auto start = std::chrono::high_resolution_clock::now();
        //calculate result
        std::this_thread::sleep_for(ms100); // time waster for test
        // output result.
        std::cout <<start.time_since_epoch().count() << ":" << count << std::endl;
        auto delta = std::chrono::high_resolution_clock::now() - start;
        auto sleeptime =ms100 - delta;
        std::this_thread::sleep_for(sleeptime);
    }/*
    auto now = std::chrono::system_clock::now().time_since_epoch();
    auto t100ms = std::chrono::milliseconds(100);
    auto time = now + t100ms;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(time).count();*/
}

// int main()
// {
//     // start thread and call taskloop
//     std::thread testthread(taskloop);
//     // wait for thread to end.
//     testthread.join();
// }

/*****************************************************/
#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <unistd.h>

std::mutex mutex;
static int count = 10;

void thread1_r()
{
    for(int i = 0; i < 10000; i++) {
        mutex.lock();
        count++;
        mutex.unlock();
    }
}

void thread2_r()
{
    for(int i = 0; i < 10000; i++) {
        mutex.lock();
        count--;
        mutex.unlock();
    }
}

void errorExit(const std::string& strerr)
{
    std::cerr << strerr << std::endl;
    std::exit(EXIT_FAILURE);
}

int main()
{
    unsigned int miliseconds = 100000;
    std::thread thread1(thread1_r);
    std::thread thread2(thread2_r);

    if (thread1.joinable()) thread1.join();
    if (thread2.joinable()) thread2.join();
    for (size_t i = 0; i < 10; ++i)
    {
        /* code */
        // auto start = std::chrono::high_resolution_clock::now();
        // std::cout <<start.time_since_epoch().count() << ":" << i << std::endl;
        
        // std::time_t t = std::time(nullptr); //get EPOCH time
        // std::cout << t << ":" << i << std::endl;

        double now = std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now().time_since_epoch()).count(); //get EPOCH time
        std::cout << std::fixed << std::setprecision(0) << now << ":" << i << std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        usleep(miliseconds);
    }

    std::cout << "Count value " << count << std::endl;

    return 0;
}

