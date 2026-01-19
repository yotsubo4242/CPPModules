#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ScavTrap Orianna;
	FragTrap Blitzcrank;

	std::cout << "\033[33m--- Battle Start ----\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m--- Round 1 ----\033[0m" << std::endl;
	Orianna.attack("Blitzcrank");
	Blitzcrank.takeDamage(20);

	std::cout << std::endl;
	std::cout << "\033[33m--- Round 2 ----\033[0m" << std::endl;
	Blitzcrank.attack("Orianna");
	Orianna.takeDamage(30);

	std::cout << std::endl;
	std::cout << "\033[33m--- Round 3 ----\033[0m" << std::endl;
	Orianna.guardGate();

	std::cout << std::endl;
	std::cout << "\033[33m--- Round 4 ----\033[0m" << std::endl;
	Blitzcrank.highFivesGuys();

	std::cout << std::endl;
	std::cout << "\033[33m--- Battle End ----\033[0m" << std::endl;
	return (0);
}

/*
ScavTrap
	- HP: 100
	- EP: 50
	- AD: 20

FragTrap
	- HP: 100
	- EP: 100
	- AD: 30
*/
