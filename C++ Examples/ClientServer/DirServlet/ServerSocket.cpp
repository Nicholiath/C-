#include "ServerSocket.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

ServerSocket::ServerSocket(int port) {
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(port); 
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("Opening stream socket");
	}
	if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
		perror("Binding stream socket");
	}
	listen(sock, 5);
}
Socket* ServerSocket::acceptSocket() {
	sockaddr_in localAddr, remoteAddr;
	int addrLen = sizeof(remoteAddr);	
	int asock = accept(sock, (struct sockaddr *)&remoteAddr, &addrLen); 	
	Socket *as = new Socket(asock);
	return as;
}

