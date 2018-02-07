#ifndef HTTPSERVELET_H
#define HTTPSERVELET_H

#include "HttpRequest.h"
#include "HttpResponse.h"

class HttpServlet {
public:
	virtual void doGet(HttpRequest *request, HttpResponse *response) = 0;
	virtual void doPost(HttpRequest *request, HttpResponse *response) = 0;
	virtual ~HttpServlet() {}
};

#endif 