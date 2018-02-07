#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include "Socket.h"
class ServerSocket {
public:
	ServerSocket(int port);
	Socket* Accept();
	~ServerSocket();
private:
	int sock;
};

#endif 