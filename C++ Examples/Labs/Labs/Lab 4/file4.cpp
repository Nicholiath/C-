#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

string rtrim(const string& s) {
	size_t a, b;
	a = s.find_first_of(' ');
    b = s.find_last_not_of(' ');
    return s.substr(a, b);
	
}

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

string& reverse(string& s) {
	int a = s.size();
	size_t i, j=s.size();
	for (i=0;i<(a/2);i++) {
		j--;
		swap(s[j], s[i]);
		
	}
	return s;
}

string replace_all(string& s, const string& os, const string& ns) {
    size_t start = 0;
	size_t end;
    while((start = s.find(os, start)) != std::string::npos) {
        end = start + os.length();
        s.replace(start, end, ns);
        start += ns.length();
    }
	return s;
}

string squeeze_spaces(const string& s) {
	size_t i, j;
	string c(s);
	for (i=0;i<c.size();i++) {
		if (isspace(c[i]) /*&& isspace(c[i+1])*/) {
			j = s.find_first_not_of("\n\t ", i);
			
			//find next non space and set as int
			c.replace(i, j-i, " ");
		}
	}                                        
	return c;
}

int main(void) {
	/*cout << rtrim("   hello world\t ");*/
	/*string s("hello");
	cout << reverse(s) << ' ';
	cout << s;*/
	/*string s("hello all");
	cout << replace_all(s, "ll", "nn");*/
	cout << squeeze_spaces(" \thomer \n simpson  ");
	cout << "hi";
	
}




