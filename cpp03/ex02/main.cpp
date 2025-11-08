#include <ScavTrap.hpp>
#include <FragTrap.hpp>

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
