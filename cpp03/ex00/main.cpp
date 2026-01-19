#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap Orianna;
	ClapTrap Blitzcrank("Blitzcrank");

	Orianna.attack("Blitzcrank");
	Blitzcrank.takeDamage(0);
	Blitzcrank.beRepaired(0);
	return (0);
}

/*
ClapTrap
	- HP: 10
	- EP: 10
	- AD: 0
*/
