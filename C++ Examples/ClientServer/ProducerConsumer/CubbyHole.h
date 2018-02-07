#ifndef CUBBY_HOLE_H
#define CUBBY_HOLE_H

#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <condition_variable>

class CubbyHole {
public:
	CubbyHole() {}

	void put(int number, int value);

	int get(int number);

	~CubbyHole();
private:
	std::mutex mutex_;
	std::condition_variable cond_;
	int contents_ = 0;
	bool available_ = false;
};

#endif