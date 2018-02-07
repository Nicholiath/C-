#include "Socket.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/dir.h>
#include <iostream>
Socket::Socket(int sock) {
	this->sock = sock;
}
Socket* Socket::socketConnect(struct sockaddr_in server) {
	int connectSocket = 0;

	if (connectSocket = connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
		perror("connecting");
	}
	Socket *connectedSocket = new Socket(connectSocket);
	return connectedSocket;
}
char* Socket::getRequest() {
	int rval;
	char *buf = new char[1024];
	if ((rval = read(sock, buf, 1024)) < 0) {
		perror("reading socket");
	} else {
		printf("%s\n", buf);
	}
	return buf;
}
char* Socket::sendResponse(char *res) {
	int rval;
	char res_[1024];
	strcpy(res_, "HTTP/1.1 200 ok\r\n\r\n");
	strcpy(res_, res);
	if ((rval = write(sock,(const char *)res_, strlen(res_))) < 0) {
		perror("writing socket");
	} else {
		printf("%s\n", res);
	}
}
Socket::~Socket() {}




