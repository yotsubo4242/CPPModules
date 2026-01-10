#include <Zombie.hpp>
#include <iostream>

Zombie	*newZombie(std::string name) {
	Zombie *res;
	try {
		res = new Zombie(name);
	} catch (const std::bad_alloc& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		return (NULL);
	}
	return (res);
}
