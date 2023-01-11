#include <iostream>
#include "kovian.h"

int main() {
	kovian::MarkovChain<5> mc({
		0.1, 0.3, 0.4, 0.0, 0.2,
		0.0, 0.0, 0.0, 0.0, 1.0,
		0.0, 0.5, 0.5, 0.0, 0.0,
		0.0, 0.1, 0.1, 0.1, 0.1,
		0.1, 0.1, 0.1, 0.1, 0.1});
	mc.setState(3); std::cout << "3 -> ";
	while(mc.advance() != 0) {
		std::cout << mc.current() << " -> ";
	} std::cout << "0" << std::endl;
	return 0;
}
