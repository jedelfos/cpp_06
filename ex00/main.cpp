#include <iostream>
#include "TypeId.hpp"

int main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << "erreur parametre" << std::endl;
		return 1;
	}

	TypeId		type(argv[1]);

	type.print_int();
	type.print_char();
	type.print_float();
	type.print_double();

	return 0;
}
