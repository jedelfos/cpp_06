#include "class.hpp"

int main () {

	Base*	random = generate();

	identify(*random);
	identify(random);

	delete random;
	return 0;
}