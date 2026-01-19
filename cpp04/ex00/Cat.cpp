#include "Cat.hpp"

Cat::Cat() {
	this->type = "cat";
	std::cout << "This is Cat Constructor!" << std::endl;
};

Cat::Cat(const Cat &other) {
	this->type = other.type;
	std::cout << "This is Cat Copy Constructor!" << std::endl;
};

Cat::~Cat() {
	std::cout << "This is Cat Destructor!" << std::endl;
};

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "This is Cat Copy Assignment Operator!" << std::endl;
	return (*this);
};

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
};
