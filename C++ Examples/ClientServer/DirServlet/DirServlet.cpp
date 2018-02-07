#include "DirServlet.h"
#include "Dir.h"
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <pthread.h>

DirServlet::DirServlet() {
	
}

void DirServlet::doGet(HttpRequest *req, HttpResponse *res) {
	char *rd = new char[1024];
	char *rq = new char[1024];
	rq = req->getRequestData();
	strcpy(rd, rq);
	Dir dir = Dir(rd);
	rd = dir.getDir();
	res->getResponseData(rd);
}

void DirServlet::doPost(HttpRequest *req, HttpResponse *res) {
	
}
