#include <Zombie.hpp>
#include <iostream>

Zombie::Zombie() {
	std::cout << "\033[31m Hi! I'm new zombieeeeee. \033[m" << std::endl;
	return ;
}

Zombie::~Zombie() {
	std::cout << "destructed zombie's name is " << this->name << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name) {
	this->name = name;
}
