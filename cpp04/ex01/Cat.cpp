#include <Cat.hpp>

Cat::Cat() {
	this->type = "cat";
	std::cout << "This is Cat Constructor!" << std::endl;
};

Cat::~Cat() {
	std::cout << "This is Cat Destructor!" << std::endl;
};

void	Cat::makeSound() {
	std::cout << "Meow" << std::endl;
};
