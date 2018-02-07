#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

void print(const vector<string>& v) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

bool is_anagram(string s1, string s2) {
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}

int main(void) {
	size_t i, j;
	string line;
	vector<string> words;
	vector<vector<string>> result;
	while (1) {
		string word;
		if (!getline(cin, line)) {
			cin.clear();
			break;
		}
		istringstream iss(line);
		iss >> word;
		words.push_back(word);
	}
	for (i=0;i<words.size();i++) {
		vector<string> anagram;
		anagram.push_back(words[i]);
		for (j=0;j<words.size();j++) {
			if (words[i] != words[j] && (is_anagram(words[i], words[j])==1)) {
				anagram.push_back(words[j]);
				words.erase(words.begin()+j);
			}
		}
		result.push_back(anagram);
	}
	for (i = 0; i < result.size(); i++) {
		print(result[i]);
	}
}



