#include <iostream>
#include <string>
#include <ctime>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#define PORT	 8080
#define MAXLINE 1024

int main()
{
        int sockfd;
	char buffer[MAXLINE];
	struct sockaddr_in servaddr, client_addr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&client_addr, 0, sizeof(client_addr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	socklen_t len;
	int n;
    while (true)
    {
        char rd[100];
        char sd[100];
        //struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        recvfrom(sockfd, rd, sizeof(rd), 0, (struct sockaddr *)&client_addr, &client_addr_len);
        time_t t = time(0);
        std::string time = ctime(&t);
        strcpy(sd, time.c_str());
        sendto(sockfd, sd, sizeof(sd), 0, (struct sockaddr *)&client_addr, client_addr_len);
        std::cout << "Done !!" << std::endl;
    }
    return 0;
}
