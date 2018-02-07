#include "Dir.h"
#include "DirServlet.h"
#include "Socket.h"
#include "ServerSocket.h"
#include "ServerThread.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <resolv.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <resolv.h>
#include <unistd.h>

ServerThread::ServerThread(Socket* socket) {
	this->socket = socket;
}

void ServerThread::sTread(void) {
	pthread_t tid;
	int result = pthread_create(&tid, 0, ServerThread::crun, this);
	if (result == 0) { 
		pthread_detach(tid);
	}
}

void* ServerThread::run(void) {
	HttpRequest *req = new HttpRequest(socket);
	HttpResponse *res = new HttpResponse(socket);
	DirServlet *ds = new DirServlet();
	ds->doGet(req, res);
	return 0;
}

ServerThread::~ServerThread() {}



