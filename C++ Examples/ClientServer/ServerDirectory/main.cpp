#include "Socket.h"
#include "ServerSocket.h"
#include "Thread.h"
#include "Dir.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/dir.h>
#include <iostream>
using namespace std;

main() {
	ServerSocket *ss = new ServerSocket(8889);
	if (ss != NULL) {
		cout << "connection successful" << endl;
		while(1) {
			Socket *cs = ss->Accept();
			if (fork() == 0) {
				Thread *thread = new Thread(cs);
				thread->run();
			}
		}
	}
}


