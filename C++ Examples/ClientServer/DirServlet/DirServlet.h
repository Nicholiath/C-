#ifndef DIR_SERVLET_H
#define DIR_SERVLET_H

#include "HttpServlet.h"

class DirServlet : virtual public HttpServlet{
public:
	DirServlet();
	void doGet(HttpRequest *req, HttpResponse *res);
	void doPost(HttpRequest *req, HttpResponse *res);
};

#endif