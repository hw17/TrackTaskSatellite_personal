#ifndef CLASSCLIENT_H
#define CLASSCLIENT_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>     //to call close function
#include <netdb.h>      //Create sockets
#include <sys/socket.h> //include sockets functions

#define SOCKETFD_FAILED    -1
#define SOCKCONNEC_FAILED  SOCKETFD_FAILED
#define LOCAL_HOST         0 //0.0.0.0

class TCPClient
{
private:
    struct addrinfo hint;
    struct addrinfo *host;
    int addsockfd {0};
    int sockfd {0};
public:

    TCPClient() = default;
    TCPClient(char *port);
    TCPClient(char *port, char *server);
    ~TCPClient();
    void configConnection(char *port, char *server);
    void connectInit(void);
    std::string sreadValue(void);
    void controlServer(void);
};

#endif /* CLASSCLIENT_H */
