#include "DrawApp.h"

using namespace std;

DrawApp::DrawApp() {}

void DrawApp::draw() const {
	int count = 1;
	for (auto it=shapes_.begin(); it != shapes_.end(); ++it) {
		cerr << count++ << ": ";
		(*it) -> draw();
	}
}

void DrawApp::addShape(shared_ptr<Shape> s) {
	shapes_.push_back(s);
}

bool DrawApp::undo() {
	if (pos_<0) {
		return false;
	}
	history_[pos_] -> unexecute();
	return true;
}

bool DrawApp::redo() {
	if (pos_ == (int)(history_.size()-1)) {
		return false;
	}
	history_[pos_+1] -> execute();
	return true;
}

void DrawApp::historyPos(shared_ptr<Command>& p) {
	if (pos_ != (int)(history_.size()-1)) {
		history_.erase(history_.begin()+ pos_ + 1, history_.end());
	}
	history_.push_back(p);
	pos_ = history_.size()-1;
}

void DrawApp::run() {
	int num;
	char cmd;
	string line;
	Point delta;
	DrawApp::draw();
	while (1) {
		//cerr << "\r\n";
		cout << '>';
		if (!getline(cin, line)) {
			cin.clear();
			break;
		}
		istringstream iss(line);
		if (iss >> cmd) {
			cout << cmd << "\r\n";
			if (iss >> num) {
			if (iss >> delta) {
				/// Translate
				if (cmd == 't') {
					if (num-1 < (int)shapes_.size() && num>0) {
						shared_ptr<TranslateCommand> tc(new TranslateCommand(shapes_[num-1], delta));
						shared_ptr<Command> p(dynamic_pointer_cast<Command>(tc));
						DrawApp::historyPos(p);
						tc -> execute();
						/// Changing history size and position
						cout << history_.size() << ' ' << pos_ << "\r\n";
						DrawApp::draw();
					}
				}
			}
			/// X Reflection
			if (cmd == 'x') {
				if (num-1 < (int)shapes_.size() && num>0) {
					shared_ptr<XReflectCommand> xrc(new XReflectCommand(shapes_[num-1]));
					shared_ptr<Command> p(dynamic_pointer_cast<Command>(xrc));
					DrawApp::historyPos(p);
					xrc -> execute();
					cout << history_.size() << ' ' << pos_ << "\r\n";
					DrawApp::draw();
				}
			}
			/// Y Reflection
			if (cmd == 'y') {
				if (num-1 < (int)shapes_.size() && num>0) {
				shared_ptr<YReflectCommand> yrc(new YReflectCommand(shapes_[num-1]));
				shared_ptr<Command> p(dynamic_pointer_cast<Command>(yrc));
				DrawApp::historyPos(p);
				yrc -> execute();
				cout << history_.size() << ' ' << pos_ << "\r\n";
				DrawApp::draw();
				}
			}
			}
			/// Undo
			if (cmd == 'u') {
				if (undo()) {					
					pos_--;
					cout << history_.size() << ' ' << pos_ << "\r\n";
					draw();
				}
			}
			/// Redo
			if (cmd == 'r') {
				if(redo()) {
					pos_++;
					cout << history_.size() << ' ' << pos_ << "\r\n";
					draw();
				}
			}
		} 
	}
}
