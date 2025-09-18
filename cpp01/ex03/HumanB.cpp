#include <HumanB.hpp>

void	HumanB::attack(void) {
	if (this->weapon != NULL)
		std::cout << this->name << " attacks with their " << *(this->weapon) << std::endl;
	else
		std::cout << this->name << " has no weapons..." << std::endl;
	return (0);
};

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
};
