#include "Producer.h"

void Producer::run() {
	for (int i = 0; i < 10; i++) {
		cubbyHole_.put(number_, i);
	}
}

Producer::~Producer() {}

