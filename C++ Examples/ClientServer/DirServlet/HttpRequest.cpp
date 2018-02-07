#include "HttpRequest.h"
#include "Socket.h"
#include <string.h>

Socket *sock;

char *rd = new char[1024];
char *method = new char[1024];

HttpRequest::HttpRequest(Socket *socket) {
	sock = socket;
}

char* HttpRequest::getRequestData() {
	return sock->getRequest();
}

