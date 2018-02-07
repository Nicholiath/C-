#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#define NAMESIZE 20
struct Record{
	char firstname[NAMESIZE], lastname[NAMESIZE];
	int score;
};
using namespace std;

bool get_valid_word(const string& prompt, string& word, bool (*is_valid)(const string&));
bool get_valid_int(const string& prompt, int& n, bool (*is_valid)(int));

bool get_valid_word(const string& prompt, string& word, bool (*is_valid)(const string&)) {	
	string line;
	while (1) {
		cout << prompt;						
		if (!getline(cin, line)) {			
			cin.clear();
			break;
		}
		
		istringstream iss(line);
		if (iss >> word && is_valid(word)) {			
			return true;
		}
	}
	return false;
}

bool get_valid_int(const string& prompt, int& n, bool (*is_valid)(int)) {
	string line;
	while (1) {
		cout << prompt;		
		if (!getline(cin, line)) {	
			
			cin.clear();
			break;
		}
		
		istringstream iss(line);
		if (iss >> n && is_valid(n)) {
			
			return true;
		}
	}
	return false;
}

bool is_valid_name(const string &name) {
	size_t i;
	for (i = 0; i < name.length(); i++) {
		if (!isalpha(name[i])) {
			return 0;
		}
	}
	return 1;
}

bool is_valid_int(int score) {
	if ((score > 100 || score < 0)) {
		return 0;
	}
	return 1;
}

int main(void) {
	Record rec;
	size_t i;
	string line;
	string name1, name2;
	int score;
	while (get_valid_word("Enter first name: ", name1, is_valid_name) &&
		get_valid_word("Enter last name: ", name2, is_valid_name) &&
		get_valid_int("Enter a score: ", score, is_valid_int)) {
		
	
	strcpy(rec.firstname, name1.c_str());
	strcpy(rec.lastname, name2.c_str());
	rec.score = score;
	cerr.write((const char *)&rec, sizeof(rec));
	}
}