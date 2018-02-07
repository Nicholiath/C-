#include "ServerSocket.h"
#include "Socket.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

ServerSocket::ServerSocket(int port) {
	struct sockaddr_in server;
	sock = socket (AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("opening stream socket");
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = port;
	if (bind (sock, (struct sockaddr *)&server, sizeof (server)) < 0) {
		perror ("binding stream socket");
	}
	listen(sock, 5);
}
Socket* ServerSocket::Accept() {
	int cSock = accept(sock, (struct sockaddr*)0, (socklen_t *)0);
	Socket *cs = new Socket(cSock);
	return cs;
}
ServerSocket::~ServerSocket() {}










