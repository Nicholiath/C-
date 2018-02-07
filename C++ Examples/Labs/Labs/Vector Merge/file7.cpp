#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& result) {
	for (auto it = result.begin(); it != result.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

template <typename InputIterator, typename OutputIterator>
void merge(InputIterator first1, InputIterator last1, InputIterator first2, InputIterator last2, OutputIterator result) {
	auto it = first1;
	auto it2 = first2;
	while (it < last1 && it2 < last2) {
		*result++ = *it < *it2 ? *it++ : *it2++;
	}
	while (it < last1) {
		*result++ = *it++;
	}
	while (it2 < last2) {
		*result++ = *it2++;
	}
	
}

int main(void) {
	vector<int> first1{1, 3, 6, 8, 10};
	vector<int> first2{2, 4, 5, 7 , 9};
	vector<int> result(10);
	merge(first1.begin(), first1.end(), first2.begin(), first2.end(), result.begin());
	print(result);
}