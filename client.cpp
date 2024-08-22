#include <iomanip>
#include <chrono>
#include <thread>
#include <mutex>

#include "classClient.h"
#include "time.h"
#include "mythread.h"

int main(int argc, char *argv[])
{
    char *port1 = "4001", *port2 = "4002", *port3 = "4003"; 
    char *server = LOCAL_HOST; //"0.0.0.0";

    //Create clients
    //TODO: Need to refactor this sections
    TCPClient *client1 = new TCPClient();
    TCPClient *client2 = new TCPClient();
    TCPClient *client3 = new TCPClient();

    //Configure clients
    //TODO: Need to refactor this sections
    client1->configConnection(port1, server);
    client2->configConnection(port2, server);
    client3->configConnection(port3, server);
    client1->connectInit();
    client2->connectInit();
    client3->connectInit();

    // Threads to handle server sockets
    std::thread t1(thread_readValues, std::ref(*client1), 1);
    std::thread t2(thread_readValues, std::ref(*client2), 2);
    std::thread t3(thread_readValues, std::ref(*client3), 3);

    // Thread to printing values
    std::thread t4(thread_printValues);

    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    if (t3.joinable()) t3.join();
    if (t4.joinable()) t4.join();

    // all done, clean-up
    delete client1;
    delete client2;
    delete client3;
    return 0;
}
