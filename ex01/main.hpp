#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <stdint.h>

struct Animal {
	std::string	name;
	int			age;
};

uintptr_t	serialize(Animal* ptr);
Animal*		deserialize(uintptr_t raw);

#endif
