#ifndef PRODUCER_H
#define PRODUCER_H

#include "CubbyHole.h"

class Producer {
public:
	Producer(CubbyHole& cubbyHole, int number) : cubbyHole_(cubbyHole), number_(number){}
	void run();
	~Producer();
private:
	CubbyHole& cubbyHole_; 
	int number_;
};

#endif