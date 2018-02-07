#ifndef SERVER_THREAD_H
#define SERVER_THREAD_H

class Thread {
public:
	Thread(Socket* socket);
	void run();
	~Thread();
private:
	Socket* socket;
};
#endif
