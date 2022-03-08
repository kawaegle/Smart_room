// Client side C/C++ program to demonstrate Socket programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 80
#define MAXSIZE 4096
#define SA struct sockaddr

void error(char *mess)
{
    printf("%s",mess);
    exit (-1);
}

int main (int argc, char *argv[])
{
    if (argc != 2)
        return (-1);
    int sock_fd = 0;
    struct sockaddr_in servaddr;
    char *get = "GET / HTTP/1.1\r\n\r\n";
    char buff[1024] = {0};

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("Socket creation error\n");

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        error("Invalid adress\n");

    if (connect(sock_fd, (SA *) &servaddr, sizeof(servaddr)) < 0)
        error("Connection failed\n");

    send(sock_fd, get, strlen(get), 0);
    printf("DATA send: %s", get);

    read(sock_fd, buff, 1024);
    printf("%s", buff);
    return 0;
}
