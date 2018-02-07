#include "Socket.h"
#include "ServerSocket.h"
#include "Dir.h"
#include "Thread.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>

Thread::Thread(Socket* socket) {
	this->socket = socket;
}

void Thread::run() {
	char *request = new char[1024];
	char *response = new char[1024];
	request = socket->getRequest();	
	Dir dir = Dir(request);
	response = dir.getDirectory();
	socket->sendResponse(response);
}

Thread::~Thread() {
}