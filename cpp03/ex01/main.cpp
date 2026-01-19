#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap Orianna;
	ClapTrap Blitzcrank("Blitzcrank");

	std::cout << "\033[33m--- Battle Start ----\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[33m--- Round 1 ----\033[0m" << std::endl;
	Blitzcrank.attack("Orianna");
	Orianna.takeDamage(0);

	std::cout << std::endl;
	std::cout << "\033[33m--- Round 2 ----\033[0m" << std::endl;
	Orianna.attack("Blitzcrank");
	Blitzcrank.takeDamage(20);
	Orianna.guardGate();

	std::cout << std::endl;
	std::cout << "\033[33m--- Round 3 ----\033[0m" << std::endl;
	Blitzcrank.attack("Orianna");
	Orianna.takeDamage(0);
	std::cout << std::endl;

	std::cout << "\033[33m--- Battle End ----\033[0m" << std::endl;
	return (0);
}

/*
ClapTrap
	- HP: 10
	- EP: 10
	- AD: 0

ScavTrap
	- HP: 100
	- EP: 50
	- AD: 20
*/