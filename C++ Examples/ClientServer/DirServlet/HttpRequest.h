#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include "Socket.h"

class HttpRequest {
public:
	HttpRequest(Socket *socket);
	char *getRequestData();
private:
	Socket *socket;
};

#endif
