#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap Orianna;
	ClapTrap Blitzcrank("Blitzcrank");

	Orianna.attack("Blitzcrank");
	Blitzcrank.takeDamage(20);
	Orianna.guardGate();
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