#include "Socket.h"
#include "HttpResponse.h"
#include <string.h>
#include <iostream>

Socket *rsock;

HttpResponse::HttpResponse(Socket *socket) {
	rsock = socket;
}

void HttpResponse::getResponseData(char *req) {
	rsock->getResponse(req);
}