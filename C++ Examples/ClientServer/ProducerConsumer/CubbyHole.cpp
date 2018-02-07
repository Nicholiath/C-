#include <mutex>
#include <condition_variable>
#include <iostream>

#include "CubbyHole.h"

using namespace std;

int CubbyHole::get(int number) {

	mutex_.lock();

	while (available_ == false) {
		unique_lock<mutex> lock(mutex_);
		cond_.wait(lock);
	}

	available_ = false;
	cout << "Consumer " << number << " got: " << contents_ << endl;
	mutex_.unlock();
	cond_.notify_all();
	return contents_;
}

void CubbyHole::put(int number, int value) {

	mutex_.lock();

	while (available_ == true) {
		unique_lock<mutex> lock(mutex_);
		cond_.wait(lock);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	contents_ = value;
	available_ = true;
	cout << "Producer " << number << " put: " << contents_ << endl;

	mutex_.unlock();
	cond_.notify_all();
}

CubbyHole::~CubbyHole() {
}

