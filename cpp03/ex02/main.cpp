#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ScavTrap Orianna;
	FragTrap Blitzcrank;

	Orianna.attack("Blitzcrank");
	Blitzcrank.takeDamage(20);
	Blitzcrank.attack("Orianna");
	Orianna.takeDamage(30);
	Orianna.guardGate();
	Blitzcrank.highFivesGuys();
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
