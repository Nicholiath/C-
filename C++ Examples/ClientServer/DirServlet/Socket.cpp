#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "Socket.h"
Socket::Socket(int sock) {
	this->sock = sock;
}
Socket* Socket::cSocket(struct sockaddr_in server) {
	int cs = 0;
	if (cs = connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
	perror("connecting");
	}
	Socket *cSocket = new Socket(cs);
	return cSocket;
}
char* Socket::pRequest(char *req) {
	char* temp;
	std::string tempStr, parsedStr;
	tempStr = std::string(req);
	parsedStr = tempStr.substr(tempStr.find_last_of('?') + 1);
	parsedStr = parsedStr.substr(0, parsedStr.find("HTTP") - 1);
	temp = new char[parsedStr.length() + 1];
	strcpy(temp, parsedStr.c_str());
	return temp;
}
char* Socket::getRequest() {
	int readSock;
	char *request = new char[1024];
	char *pr = new char[1024];
	if ((readSock = read(sock, request, 1024)) < 0) {
		perror("reading socket");
	}
	else {
		pr = pRequest(request);
	}
	return pr;
}

void Socket::getResponse(char* req) {
	int ws;
	char *res = new char[1024];	
    const char* HTTP_HEADER = "HTTP/1.1 200 ok\n\rAccess-Control-Allow-Origin: *\n\rContent-Type: text/plain\r\n\r\n";	
	strcpy(res, HTTP_HEADER);
	strcat(res, req);
	if ((ws = write(sock, (const char *)res, strlen(res))) < 0) {
		perror("Writing socket");
	}
	close(sock);
}
Socket::~Socket() {
}

