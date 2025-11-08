#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

int	main(void) {
	ScavTrap Orianna;
	ClapTrap Blitzcrank("Blitzcrank");

	Orianna.attack("Blitzcrank");
	Blitzcrank.takeDamage(20);
	Orianna.guardGate();
	return (0);
}
