#include "classClient.h"

TCPClient::TCPClient(char *port)
{
    configConnection(port, LOCAL_HOST);
}

TCPClient::TCPClient(char *port,char *server)
{
    configConnection(port, server);
}

TCPClient::~TCPClient()
{
    freeaddrinfo(host);
    close(sockfd);
}

void TCPClient::configConnection(char *port, char *server){
    //Init the struct hint with zero
    memset(&hint, 0, sizeof(hint));
    
    //Configure connection
    hint.ai_family = AF_INET;        /* IPv4 */
    hint.ai_socktype = SOCK_STREAM;  /* TCP */

    //Config host structure for socket connection
    addsockfd = getaddrinfo(server, port, &hint, &host);

    if (NETDB_SUCCESS != addsockfd){
        perror("failed");
        exit(1);
    }// Server found

    //Create socket
    sockfd = socket(host->ai_family, 
                    host->ai_socktype,
                    host->ai_protocol);
    
    //Verify endpoit file descriptor
    if (SOCKETFD_FAILED == sockfd){
        perror("failed");
        exit(1);
    }
}

void TCPClient::connectInit(void){
    //Init socket connection
    addsockfd = connect(sockfd,
                        host->ai_addr,
                        host->ai_addrlen);
    
    //Connection stablish
    if(SOCKCONNEC_FAILED == addsockfd){
        perror("failed");
        exit(1);
    }
}

std::string TCPClient::sreadValue(void){
    std::string sbuffer(BUFSIZ, 0);
    std::string tmp {0};

    //Read socket buffer
    addsockfd = recv(sockfd,
                     sbuffer.data(),
                     BUFSIZ,
                     0);
    
    if(SOCKETFD_FAILED == addsockfd){
        //close connection to client
        close(sockfd);
        //return in case 
        tmp = "++";
    }
    else{
        //Create an istringstream object and initialize it with the buffer
        std::istringstream isss(sbuffer.data());

        //parsed data 
        //extracts the available value from the stream and assigns it to num
        isss >> tmp;
    }

    return tmp;
}

void TCPClient::controlServer(void){
    std::string sbuffer(BUFSIZ, 0);
    ssize_t status {0};
    
    // send the string
	status = write(sockfd,
                   sbuffer.data(),
                   sbuffer.length());

	if(SOCKETFD_FAILED == status){
		perror("Send failed");
		exit(1);
	}
}
