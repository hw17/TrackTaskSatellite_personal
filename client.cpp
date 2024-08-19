//if include <json/value.h> line fails (latest kernels), try also:
//  #include <jsoncpp/json/json.h>
/*#include <json/value.h>
#include <fstream>

std::ifstream people_file("people.json", std::ifstream::binary);
Json::Value people;
people_file >> people;

cout<<people; //This will print the entire json object.

//The following lines will let you access the indexed objects.
cout<<people["Anna"]; //Prints the value for "Anna"
cout<<people["ben"]; //Prints the value for "Ben"
cout<<people["Anna"]["profession"]; //Prints the value corresponding to "profession" in the json for "Anna"

cout<<people["profession"]; //NULL! There is no element with key "profession". Hence a new empty element will be created.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

#include <vector>
#include "time.h"

//class Client

int main(int argc, char *argv[])
{
    const char *port = "4001", *port2 = "4002", *port3 = "4003"; // "65001" / 4001
    char *server = "0.0.0.0";
    struct addrinfo hints, *host;
    struct addrinfo hints2, *host2;
    struct addrinfo hints3, *host3;
    int r, sockfd;
    int r2, sockfd2;
    int r3, sockfd3;
    // char buffer[BUFSIZ];
    // char buffer2[BUFSIZ];
    // char buffer3[BUFSIZ];
    // std::vector<std::string> buffer(BUFSIZ);
    // std::vector<std::string> buffer2(BUFSIZ);
    // std::vector<std::string> buffer3(BUFSIZ);
    std::vector<std::string> buffer1(BUFSIZ);
    std::string buffer2;
    std::string buffer3;

    if (argc < 2)
    {
        std::cerr << "Format: client hostname" << std::endl;
        exit(1);
    }
    //server = argv[1];

    /* obtain and convert server name and port */
    std::cout << "Looking for server on " << server << "...";
    memset(&hints, 0, sizeof(hints)); /* use memset_s() */
    memset(&hints2, 0, sizeof(hints2)); /* use memset_s() */
    memset(&hints3, 0, sizeof(hints3)); /* use memset_s() */

    hints.ai_family = AF_INET;        /* IPv4 */
    hints.ai_socktype = SOCK_STREAM;  /* TCP */

    hints2.ai_family = AF_INET;        /* IPv4 */
    hints2.ai_socktype = SOCK_STREAM;  /* TCP */
    
    hints3.ai_family = AF_INET;        /* IPv4 */
    hints3.ai_socktype = SOCK_STREAM;  /* TCP */
    
    r = getaddrinfo(server, port, &hints, &host);
    r2 = getaddrinfo(server, port2, &hints2, &host2);
    r3 = getaddrinfo(server, port3, &hints3, &host3);
    if ((r != 0) || (r2 != 0) || (r3 != 0))
    {
        perror("failed");
        exit(1);
    }
    std::cout << "found" << std::endl;

    /* create a socket */
    sockfd = socket(host->ai_family, host->ai_socktype, host->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        exit(1);
    }

    sockfd2 = socket(host2->ai_family, host2->ai_socktype, host2->ai_protocol);
    if (sockfd2 == -1)
    {
        perror("failed");
        exit(1);
    }

    sockfd3 = socket(host3->ai_family, host3->ai_socktype, host3->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        exit(1);
    }

    /* connect to the socket */
    r = connect(sockfd, host->ai_addr, host->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        exit(1);
    }

    r2 = connect(sockfd2, host2->ai_addr, host2->ai_addrlen);
    if (r2 == -1)
    {
        perror("failed");
        exit(1);
    }

    r3 = connect(sockfd3, host3->ai_addr, host3->ai_addrlen);
    if (r3 == -1)
    {
        perror("failed");
        exit(1);
    }

    unsigned int miliseconds = 1000;
    std::string num1,num2,num3;
    std::ostringstream strOutput;

    /* loop to interact with the server */
    while (true)
    {
        usleep(miliseconds);
        r = recv(sockfd, buffer1.data(), BUFSIZ, 0);
        r2 = recv(sockfd2, buffer2.data(), BUFSIZ, 0);
        r3 = recv(sockfd3, buffer3.data(), BUFSIZ, 0);

        //Create an istringstream object and initialize it with the buffer data
        std::istringstream iss1(*buffer1.data());
        std::istringstream iss2(buffer2.data());
        std::istringstream iss3(buffer3.data());
        if ((r < 1) || (r2<1) || (r3<1))
        {
            puts("Connection closed by peer");
            break;
        }
        /* local input  */
        //extracts the available value from the stream and assigns it to num
        iss1 >> num1;
        iss2 >> num2;
        iss3 >> num3;
        double now = std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now().time_since_epoch()).count(); //get EPOCH time
        strOutput << "{\"timestamp\": " << std::fixed << std::setprecision(0) << now << ", "\
                  /*<< "\"-out1\": \"" << buffer1.front().substr(0,buffer1.front().find("\n")) <<"\"\t, " \*/
                  << "\"-out1\": \"" << (num1 == "" ? "--" : num1)  <<"\"\t, " \
                  << "\"-out2\": \"" << (num2 == "" ? "--" : num2) << "\"\t, " \
                  << "\"-out3\": \"" << (num3 == "" ? "--" : num3) << "\"} "<< std::endl;
        std::cout << strOutput.str();

    } /* end while loop */

    /* all done, clean-up */
    freeaddrinfo(host);
    freeaddrinfo(host2);
    freeaddrinfo(host3);
    close(sockfd);
    close(sockfd2);
    close(sockfd3);
    puts("Disconnected");

    return 0;
}

