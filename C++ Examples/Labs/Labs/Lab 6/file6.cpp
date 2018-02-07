#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& v) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

vector<vector<int> > interleave(int x, const vector<int>& v) {
	size_t i;
	vector<vector<int> > results; 	
	for (i=0;i<=v.size();i++) {
		vector<int> temp(v); 
		temp.insert(temp.begin()+i, x);
		results.push_back(temp);
	}
	return results;
}

vector<vector<int> > permute(size_t n) {
	size_t i, j;
	vector<vector<int> > results;
	if (n == 0) {
		return {{}};
	}
	auto vectors = permute(n-1);
	for (j=0;j<vectors.size();j++) {
		vector<vector<int> > v = interleave(n, vectors[j]);
		for (i=0;i<v.size();i++) {
			results.push_back(v[i]);
		}
	}
	return results;
}

int main(void) {
	size_t i;
	//vector<int> v {1,2,3};
	//vector<vector<int> > results = interleave(4, v);
	vector<vector<int> > results = permute(4);
	for (i=0;i<results.size();i++) {
			print(results[i]);		
	}
}


