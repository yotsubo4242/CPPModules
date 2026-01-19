#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap Orianna;
	ClapTrap Blitzcrank("Blitzcrank");

	for (int i = 0; i < 11; i++) {
		std::cout << "\033[33m--- Round " << i + 1 << " ----\033[0m" << std::endl;
		Orianna.attack("Blitzcrank");
		Blitzcrank.takeDamage(0);
		Blitzcrank.beRepaired(0);
		std::cout << std::endl;
	}
	return (0);
}

/*
ClapTrap
	- HP: 10
	- EP: 10
	- AD: 0
*/
