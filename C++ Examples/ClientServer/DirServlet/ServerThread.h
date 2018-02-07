#ifndef SERVER_THREAD_H
#define SERVER_THREAD_H

#include "Socket.h"

class ServerThread {
public:
	ServerThread(Socket* socket);
	void sTread();
	static void* crun(void *arg) { return ((ServerThread*)arg)->run();}
	void* run(void);
	~ServerThread();
private:
	Socket* socket;
};

#endif
