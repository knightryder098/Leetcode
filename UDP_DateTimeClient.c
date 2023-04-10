// Client side implementation of UDP client-server model
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace std;
#define PORT	 8080
#define MAXLINE 1024

// Driver code
int main() {
	int cs;
	char rd[MAXLINE], sd[MAXLINE];
	struct sockaddr_in servaddr;

	// Creating socket file descriptor
	if ( (cs = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int n;	
	socklen_t len = sizeof(servaddr);

    sendto(cs, sd, sizeof(sd), 0, (struct sockaddr *)&servaddr, len);

    recvfrom(cs, rd, sizeof(rd), 0, (struct sockaddr *)&servaddr, &len);

    std::string time(rd);

    std::cout << time << std::endl;

    close(cs);
	return 0;
}

