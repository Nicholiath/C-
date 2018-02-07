#include <unistd.h>
#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <pthread.h>
#include "Socket.h"
#include "ServerSocket.h"
#include "ServerThread.h"
using namespace std;

int main() {
	ServerSocket *ss = new ServerSocket(8888);
	if (ss == NULL) {
		throw "error occurs";
	}
	else {
		cout << "Connection success" << endl;
		while (1) {
			Socket *socket = ss->acceptSocket();

			ServerThread *st = new ServerThread(socket);
			st->sTread();
		}
	}
}
