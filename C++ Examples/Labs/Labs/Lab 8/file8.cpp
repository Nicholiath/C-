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

typedef map<string, int> CourseScore;

struct Grades {
	string id;
	map<string,int> scores; // course, score, eg. COMP3512, 86
};

struct Cmp {
	string course;
	Cmp(const string& l): course(l) {}
	bool operator()(const Grades& g1, const Grades& g2) const {
		return g1.scores.find(course)->second > g2.scores.find(course)->second;
	}
};

struct Stats {
	string course;
	int average;
	Stats(const string& l): course(l) {}
	void operator()(const Grades& g1) {
		average = average + g1.scores.find(course)->second; 
	}
	int result() {
		average = average/2;
		return average;
	}
};

ostream& operator<<(ostream& os, const Grades& g) {
	os << g.id << "\r\n" << g.scores.size() << "\r\n";
	for (const auto& x : g.scores) {
		os << x.first << ' ' << x.second << "\r\n";
	}
	os << "\r\n";
	return os;
}

istream& operator>>(istream& input, Grades& g) {
	g.scores.clear();
	int value;
	input >> g.id >> value;
	for(int i = 0; i < value; i++) {
		string course_num;
		int grade_num;
		input >> course_num >> grade_num;
		g.scores.insert(pair<string, int>(course_num, grade_num));
	}
	return input;
}

int main(void) {
	size_t i;
	vector<Grades> v1;
	string line;
	while(1) {
		Grades g;
		CourseScore courseScore;
		string a;
		int n;
		int scoreInt;
		string score;
		string id, course;
		if (!getline(cin, line)) {
			cin.clear();
			break;
		}
		istringstream iss(line);
		iss >> a;
		if (a[0]=='a') {
			id = a;
			getline(cin, line);
			istringstream ss(line);
			ss >> n;
			for (i=0;i<n;i++) {
				getline(cin, line);
				istringstream ass(line);
				ass >> course;
				ass >> scoreInt;
				courseScore.insert(make_pair(course, scoreInt));
			}
		}
		g.id = id;
		g.scores = courseScore;
		v1.push_back(g);
	}
	sort(v1.begin(), v1.end(), Cmp("COMP3512"));
	Stats a = for_each(v1.begin(), v1.end(), Stats("COMP3512"));
	for (i=0;i<v1.size()-1;i++) {
		//cout << v1[i];
	}
}






