#include <Zombie.hpp>
#include <iostream>

Zombie *zombieHorde(int N, std::string name) {
	std::cout << "now, in the zombieHorde() function" << std::endl;
	Zombie *res;
	try {
		res = new Zombie[N];
	} catch (std::bad_alloc& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++) {
		res[i].setName(name);
	}
	return (res);
}
