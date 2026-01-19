#include "Dog.hpp"

Dog::Dog() {
	std::cout << "This is Dog Constructor!" << std::endl;
	this->type = "dog";
	this->brain = new Brain();
};

Dog::Dog(const Dog &other) {
	std::cout << "This is Dog Copy Constructor!" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*(other.brain));
};

Dog::~Dog() {
	std::cout << "This is Dog Destructor!" << std::endl;
	delete this->brain;
};

Dog &Dog::operator=(const Dog &other) {
	std::cout << "This is Dog Copy Assignment Operator!" << std::endl;
	if (this != &other) {
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	return (*this);
};

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
};
