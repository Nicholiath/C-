#include "Consumer.h"

void Consumer::run() {
	int value = 0;

	for (auto i = 0; i < 10; i++) {
		value = cubbyHole_.get(number_);
	}
}

Consumer::~Consumer() {}