#ifndef SOCKET_H
#define SOCKET_H

class Socket {
public:
	Socket(int sock);
	Socket* socketConnect(struct sockaddr_in server);
	char* getRequest();
	char* sendResponse(char* res);
	~Socket();
private:
	int sock;
};
#endif