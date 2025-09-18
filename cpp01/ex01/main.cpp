#include <Zombie.hpp>
#include <iostream>

Zombie *zombieHorde(int, std::string);

int	main(void) {
	int			N;
	std::string	name;

	std::cout << "\033[34m please input num of zombie. \033[m" << std::endl;
	std::cin >> N;
	std::cin.clear();
	std::cout << "\033[34m please input zombie's name. \033[m" << std::endl;
	std::cin >> name;
	std::cin().clear();

	std::cout << "\033[33m Testing zombieHorde() function... \033[m" << std::endl;
	Zombie *horde = zombieHorde(N, name);
	std::cout << "\033[33m DONE: Testing zombieHorde() function!! \033[m" << std::endl;

	delete[] horde;
	return (0);
}
