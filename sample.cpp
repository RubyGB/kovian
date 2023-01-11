#include <iostream>
#include "kovian.h"

int main() {
	using namespace kovian::aliases;
	kovian::MarkovChain<5> mc("sample1.kov");
	/*kovian::MarkovChain<5> mc(TM<5>{
		0.1, 0.3, 0.4, 0.0, 0.2,
		0.0, 0.0, 0.0, 0.0, 1.0,
		0.0, 0.5, 0.5, 0.0, 0.0,
		0.0, 0.1, 0.1, 0.1, 0.1,
		0.1, 0.1, 0.1, 0.1, 0.1});*/
	mc.setState(3);
	std::cout << "3 -> ";
	while(mc.advance() != 0) {
		std::cout << mc.current() << " -> ";
	}
	std::cout << "0" << std::endl;
	return 0;
}
