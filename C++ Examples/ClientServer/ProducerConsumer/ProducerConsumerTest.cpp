#include "CubbyHole.h"
#include "Producer.h"
#include "Consumer.h"

int main() {
	CubbyHole cubbyhole;
	Producer p(cubbyhole, 0);
	Consumer c(cubbyhole, 0);

	std::thread producer_thread(&Producer::run, &p);
	std::thread consumer_thread(&Consumer::run, &c);

	producer_thread.join();
	consumer_thread.join();

	return 0;
}