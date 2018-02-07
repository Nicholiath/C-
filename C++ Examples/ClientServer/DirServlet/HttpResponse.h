#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include "Socket.h"

class HttpResponse {
public:
	HttpResponse(Socket *socket);
	void getResponseData(char* req);
private:
	Socket *socket;
};

#endif
