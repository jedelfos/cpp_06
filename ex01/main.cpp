#include "main.hpp"

int main() {

	Animal		cat = { "fat cat", 5 };
	uintptr_t	raw;
	Animal*		ptr;

	std::cout << "name: '"<< cat.name << "' age: " << cat.age << std::endl;

	raw = serialize(&cat);
	ptr = deserialize(raw);

	std::cout << "name: '"<< ptr->name << "' age: " << ptr->age << std::endl;

	cat.age++;

	std::cout << "name: '"<< cat.name << "' age: " << cat.age << std::endl;
	std::cout << "name: '"<< ptr->name << "' age: " << ptr->age << std::endl;

	return 0;
}

uintptr_t	serialize(Animal* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Animal*		deserialize(uintptr_t raw) {
	return reinterpret_cast<Animal *>(raw);
}
