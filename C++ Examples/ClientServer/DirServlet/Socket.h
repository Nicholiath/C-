#ifndef SOCKET_H
#define SOCKET_H

class Socket {
public:
	Socket(int sock);	
	Socket* cSocket(struct sockaddr_in server);
	char* pRequest(char *request);
	char* getRequest();
	void getResponse(char* res);
	~Socket();
private:
	int sock;
};

#endif 