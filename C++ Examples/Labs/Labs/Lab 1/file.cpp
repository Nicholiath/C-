/* g++ -std=c++11 -W -Wall -pedantic file.cpp -o file */
/* control + D exits while loop (b-a+1)*/
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	if (argc == 1) {
		while (cin >> n ) {
			if (n < 0) {cout << "-";} else {cout << "+";}
			cout << setw(10);		
			cout << abs(n) << "\r\n";
		}
	} else if (strcmp(argv[1],"-x")==0) {
		while (cin >> n) {
			if (n >= 0) {
				cout << setw(10);		
				cout << hex << uppercase << n << "\r\n";
			}
		}
	} else if (strcmp(argv[1],"-o")==0) {
		while (cin >> n) {
			if (n >= 0) {
				cout << setw(10);		
				cout << oct << n << "\r\n";
			}
		}		
	}
}