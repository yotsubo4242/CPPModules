#include <Zombie.hpp>
#include <iostream>

Zombie::Zombie(std::string name): name(name) {};

Zombie::~Zombie() {
	std::cout << "destructed zombie's name is " << this->name << std::endl;
};

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
