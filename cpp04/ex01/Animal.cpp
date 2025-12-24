#include <Animal.hpp>

Animal::Animal() {
	this->type = "";
	this->brain = new Brain();
	std::cout << "This is Animal Constructor!" << std::endl;
};

Animal::~Animal() {
	std::cout << "This is Animal Destructor!" << std::endl;
};

void	Animal::makeSound() {
	delete	this->brain;
	std::cout << "pikapika" << std::endl;
};
