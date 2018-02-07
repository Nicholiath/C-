#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Socket.h"
using namespace std;
main() {
	int sock;
	struct sockaddr_in server;
	int msgsock;
	char buf[1024];
	struct hostent *hp;
	char *host = "127.0.0.1";
	int rval;
	char *buffer = new char[512];
	char *result = new char[512];
	// 
	sock = socket (AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
	perror("opening stream socket");
	}

	bzero(&server, sizeof(server));
	hp = gethostbyname("localhost");
	bcopy((char*)hp->h_addr, (char*)&server.sin_addr, hp->h_length);
	server.sin_family = AF_INET;
	server.sin_port = 8889;

	Socket *socket = new Socket(sock);
	socket->socketConnect(server);cin.clear();
	cout << "Directory: ";
	if (cin >> buffer) {		
	socket->sendResponse(buffer);
	}
		
	result = socket->getRequest();
	
	cout << result << endl;
}
