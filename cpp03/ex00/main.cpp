#include <ClapTrap.hpp>

int	main(void) {
	ClapTrap Orianna;
	ClapTrap Blitzcrank("Blitzcrank");

	Orianna.attack("Blitzcrank");
	Blitzcrank.takeDamage(0);
	Blitzcrank.beRepaired(0);
	return (0);
}
