#include <string>
#include <ostream>
#include <map>
#include "optionstudent.h"
using namespace std;

int main(void) {
	OptionStudent os("A00891429", "Homer", "Simpson", 3, "WM");
	os.display(cout);
	cout << "\r\n";
	os.print(cout);
}