#include <iostream>
#include <string>
#include <ctime>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 

int main()
{
    int server_socket;
    int port = 5217;
    struct sockaddr_in server_address;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(server_socket, 5);
    while(true)
    {
        std::cout << "Waiting For Connection ..." << std::endl;
        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);
        char server_date[100];
        time_t now = time(0);
        strftime(server_date, sizeof(server_date), "Server Date %c\n", localtime(&now));
        send(client_socket, server_date, sizeof(server_date), 0);
        close(client_socket);
    }
    return 0;
}
