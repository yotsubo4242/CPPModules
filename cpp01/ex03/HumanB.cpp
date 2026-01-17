#include <HumanB.hpp>

HumanB::HumanB(std::string name): name(name), weapon(NULL) {
	return ;
};

void	HumanB::attack(void) {
	if (this->weapon != NULL)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapons..." << std::endl;
	return ;
};

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
};
