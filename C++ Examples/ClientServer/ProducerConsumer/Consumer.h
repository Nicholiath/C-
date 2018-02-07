#ifndef CONSUMER_H
#define CONSUMER_H

#include "CubbyHole.h"

class Consumer {
public: 
	Consumer(CubbyHole& cubbyHole, int number) : cubbyHole_(cubbyHole), number_(number) {}
    void run(); //who
	~Consumer();
private: 
	CubbyHole& cubbyHole_;
	int number_;
};

#endif