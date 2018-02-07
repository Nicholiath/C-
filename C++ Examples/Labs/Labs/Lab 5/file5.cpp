#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> tokenize(const string& s, const string& delim) {
	vector<string> tokens;
	string::size_type lastPos = s.find_first_not_of(delim, 0);
	string::size_type pos = s.find_first_of(delim, lastPos);
	while (string::npos != pos || string::npos != lastPos) {  
		tokens.push_back(s.substr(lastPos, pos - lastPos));
		lastPos = s.find_first_not_of(delim, pos);
		pos = s.find_first_of(delim, lastPos);	  
	}
	return tokens;
}

vector<string> tokenize2(const string& s, const string& delim) {
	vector<string> tokens;
    size_t pos = 0; 
	size_t lastPos = 0;
    while ((pos = s.find_first_of(delim, lastPos)) != string::npos) {
        tokens.push_back(s.substr(lastPos, pos-lastPos+1));
        lastPos = pos+1;
    }
    return tokens;
}

vector<string> split(const string& s, const string& delim) {
	vector<string> tokens;
	string::size_type lastPos = 0;
	string::size_type pos = s.find_first_of(delim, lastPos);
	while (string::npos != pos && string::npos != lastPos) {  
	  tokens.push_back(s.substr(lastPos, pos - lastPos));
	  lastPos = pos+1;
	  pos = s.find_first_of(delim, lastPos);	  
	}
	tokens.push_back(s.substr(lastPos, pos - lastPos));
	return tokens;
}

int main(void) {
	string s;
	//vector<string> tokens = tokenize("ab<cd>ef<gh>i", "<>");
	//vector<string> tokens = tokenize("<ab><>cd<", "<>");
	vector<string> tokens = tokenize2("<ab><>cd<", "<>");
	//vector<string> tokens = split("<ab><>cd<", "<>");
	//vector<string> tokens = split("ab<cd>ef<gh>i", "<>");
	for (size_t i = 0; i < tokens.size(); ++i) {
		cout << tokens[i] << endl;
	}
}


