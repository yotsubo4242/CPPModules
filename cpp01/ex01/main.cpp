#include <Zombie.hpp>
#include <iostream>

# define N 8
# define NAME "John"

Zombie *zombieHorde(int, std::string);

int	main(void) {
	std::cout << "\033[33m Testing zombieHorde() function... \033[m" << std::endl;
	Zombie *horde = zombieHorde(N, NAME);
	if (horde == NULL)
		return (1);
	std::cout << "\033[33m DONE: Testing zombieHorde() function \033[m" << std::endl;

	std::cout << "\033[33m Testing announce() each zombie \033[m" << std::endl;
	for (int i = 0; i < N; i++)
		horde[i].announce();
	std::cout << "\033[33m DONE: Testing announce() function \033[m" << std::endl;

	delete[] horde;
	return (0);
}
