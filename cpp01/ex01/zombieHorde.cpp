#include <Zombie.hpp>
#include <iostream>

Zombie *zombieHorde(int N, std::string name) {
	std::cout << "now, in the zombieHorde() function" << std::endl;
	Zombie *res = new Zombie[N];
	for (int i = 0; i < N; i++) {
		std::cout << "\033[33m Testing setName() function..." << std::endl;
		res[i].setName(name);
		std::cout << "\033[33m Testing announce() function..." << std::endl;
		res[i].announce();
	}
	return (res);
}
