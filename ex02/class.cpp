#include "class.hpp"

Base*	generate() {
	int	i;

	srand(time(0));
	i = rand() % 3;

	if (i == 0) {
		return new A;
	} else if (i == 1) {
		return new B;
	} else {
		return new C;
	}
}

void	identify( Base& ref ) {
	try {
		(void)dynamic_cast<A&>(ref);
		std::cout << "A" << std::endl;
	}
	catch (std::exception& e) {
		try {
			(void)dynamic_cast<B&>(ref);
			std::cout << "B" << std::endl;
		}
		catch (std::exception& e) {
			try {
				(void)dynamic_cast<C&>(ref);
				std::cout << "C" << std::endl;
			}
			catch (std::exception& e) {
				std::cout << "Never reach" << std::endl;
			}
		}
	}
}

void	identify( Base* ptr ) {
	if (dynamic_cast<A*>(ptr)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(ptr)) {
		std::cout << "B" << std::endl;
	} else  if (dynamic_cast<C*>(ptr)){
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Never reach" << std::endl;
	}
}
