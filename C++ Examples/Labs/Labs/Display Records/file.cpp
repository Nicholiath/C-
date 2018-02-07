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

typedef pair<string, string> Name;

struct Record {
	string date;
	Name name;
	double payment;
};
void output(const map<Name,double>& m) {
	for (const auto& x : m) {
		cout << x.first.first << ' ' << x.first.second << ' ' << x.second;
	}
	cout << "\r\n";
}
struct countsEmps {
	int *distinct;
	countsEmps(int *distinct_) : distinct(distinct_) {}
	void operator()(map<Name,double>& m) {
		(*distinct)++;
	}
};
struct endAmount {
	double *totalPaid;
	endAmount(double *totalPaid_) : totalPaid(totalPaid_) {}
	void operator()(map<Name,double>& m) {
		(*totalPaid) = (*totalPaid) + m.begin()->second; 
	}
};
//eg. should be both values in one
struct endAmount {
	double *totalPaid=0, *distinct=0;
	endAmount(double *totalPaid_, in *distinct_) : totalPaid(totalPaid_), distinct(distinct_) {}
	void operator()(map<Name,double>& m) {
		(*totalPaid) = (*totalPaid) + m.begin()->second; 
	}
};
int main(void) {
	size_t i, j;
	string line;
	double totalAmount = 0;
	vector<Record> v;
	vector<map<Name,double>> totals;
	while (1) {
		Record record;
		string fname, lname;
		if (!getline(cin, line)) {
			cin.clear();
			break;
		}
		istringstream iss(line);
		iss >> record.date >> fname >> lname >> record.payment;
		record.name = make_pair(fname, lname);
		v.push_back(record);
	}
	vector<Record> v2 = v;
	for (i=0;i<v.size();i++) {
		map<Name,double> paid;
		double total=0;
		for (j=i;j<v.size();j++) {
			if (v[i].name == v[j].name) {
				total += v[j].payment;
			}			
		}
		paid.insert(pair<Name,double>(v[i].name, total));
		totals.push_back(paid);
	}
	// problem: erasing opposite of what i want
	for (i=0;i<totals.size();i++) {
		for (j=0;j<totals.size()-1;j++) {
			if (totals[i].begin()->first.first == totals[j].begin()->first.first) {
				totals.erase(totals.begin()+j);
			}
		}
	}
	int distinct=0;
	double totalPaid=0;
	for_each(totals.begin(), totals.end(), output);
	for_each(totals.begin(), totals.end(), countsEmps(&distinct));
	for_each(totals.begin(), totals.end(), endAmount(&totalPaid));
	cout << "* Distinct employees: " << distinct << "\r\n";
	cout << "* Total amount: " << totalPaid;
}





