#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "This is Dog Constructor!" << std::endl;
};

Dog::Dog(const Dog &other) {
	this->type = other.type;
	std::cout << "This is Dog Copy Constructor!" << std::endl;
};

Dog::~Dog() {
	std::cout << "This is Dog Destructor!" << std::endl;
};

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "This is Dog Copy Assignment Operator!" << std::endl;
	return (*this);
};

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
};
