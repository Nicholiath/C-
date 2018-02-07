/* g++ -std=c++11 -W -Wall -pedantic file.cpp -o file */
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <cstring>
#include <cctype>
using namespace std;
/* eg. 1s means sort by first number, like [i][0] */
void print(const vector<string>& v) {
	ostringstream ss;
	copy(v.begin(), v.end() - 1, ostream_iterator<string>(ss, ","));
	ss << v.back();

	cout << ss.str() << "\n";
}
/* Tokenize line by comma. */
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

vector<int> strToInt(vector<string> v)
{
    vector<int> result;
    for(vector<string>::iterator it=v.begin();it!=v.end();++it) {
		istringstream iss(*it);       
		int temp;
        iss >> temp;
        result.push_back(temp);
    }
    return result;
}
// Remove char from string vector, get vectors of strings and ints and insert
vector<string> removeChars(vector<string> v) {
    vector<string> result;
    for(vector<string>::iterator it=v.begin();it!=v.end();++it) {		
		istringstream iss(*it);       
		string temp;
        iss >> temp;
        result.push_back(temp);
    }
    return result;
}

struct descS {
	bool operator()(const vector<string>& i, const vector<string>& j) { 
		return i > j; 
	}
} descenderS;

struct desc {
	bool operator()(const vector<string>& i, const vector<string>& j) {
		vector<int> v1 = strToInt(i);
		vector<int> v2 = strToInt(j);
		return v1 > v2;
	}
} descender;

struct ascS {
	bool operator()(const vector<string>& i, const vector<string>& j) { 
		return i < j; 
	}
} ascenderS;

struct asc {
	bool operator()(const vector<string>& i, const vector<string>& j) {
		vector<int> v1 = strToInt(i);
		vector<int> v2 = strToInt(j);
		return v1 < v2;
	}
} ascender;

struct multiColumn {
	bool operator()(const vector<string>& i, const vector<string>& j) { 
		return i < j; 
	}
} colSorter;

int main(int argc, const char* argv[]) {
	size_t i, j;
	vector<vector<string>> v;
	vector<string> args = tokenize(argv[1], ",");
	vector<int> argsInt = strToInt(args);
	string line;
	while(1) {		
		if (!getline(cin, line)) {
			cin.clear();
			break;
		}
		istringstream iss(line);
		v.push_back(tokenize(line, ","));
	}
	for (i=0; i<args.size(); i++) {
		if (argsInt[i] < 0) {
		/// Descending Orders
			for (size_t k=args.size()-1;args.size()>=k;k--) {
				if (args[k][2] == 's' || args[k][3] == 's') {
					for (j=args.size()-1; args.size()>=j;j--){
						int n = argsInt[j];
						stable_sort(v.begin(), v.end(), [&](const vector<string>& a, const vector<string>& b) { 
							vector<int> v1 = strToInt(a);
							vector<int> v2 = strToInt(b);
							if (v1[n-1] < v2[n-1]) {
								return true;
							}
							return false;
						});
					}
					sort(v.rbegin(), v.rend());		
				} else {
				/// Sort in ascending order, then sort w/ rbegin,rend etc
					for (j=args.size()-1; args.size()>=j;j--){
						int n = argsInt[j];
						stable_sort(v.begin(), v.end(), [&](const vector<string>& a, const vector<string>& b) { 
							vector<int> v1 = strToInt(a);
							vector<int> v2 = strToInt(b);
							if (v1[abs(n)-1] < v2[abs(n)-1]) {
								return true;
							}
							return false;
						});
					}
					reverse(v.begin(), v.end());
				}
			}
		} else {
		/// Ascending Orders
			for (size_t k=args.size()-1;args.size()>=k;k--) {
				if (args[k][1] == 's' || args[k][2] == 's') {
					for (j=args.size()-1; v.size()>j;--j){
						int n = argsInt[k];
						stable_sort(v.begin(), v.end(), [&](const vector<string>& a, const vector<string>& b) {
							if (a[n-1] < b[n-1]) {
								return true;
							}
							return false;
						});
					}
				} else {
				/// Separate chars and ints then re-insert after sort
					vector<vector<string>> onlyChars;
					for (i = 0; i < v.size(); i++) { 
						if (isalpha(v[i][0][0])) {
							onlyChars.push_back(v[i]);
						}
					}
					for (i = 0; i < v.size(); i++) { 
						if (isalpha(v[i][0][0])) {
							v.erase(v.begin()+i);
						}
					}
					for (j=args.size()-1; args.size()>=j;j--){
						int n = argsInt[j];
						stable_sort(v.begin(), v.end(), [&](const vector<string>& a, const vector<string>& b) { 
							vector<int> v1 = strToInt(a);
							vector<int> v2 = strToInt(b);
							if (v1[n-1] < v2[n-1]) {
								return true;
							}
							return false;
						});
					}
					copy(onlyChars.begin(), onlyChars.end(), back_inserter(v));
				}
			}
		}	
	}
	for (i = 0; i < v.size(); i++) {
		print(v[i]);
	}
}



