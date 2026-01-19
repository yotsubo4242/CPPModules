#include "Cat.hpp"

Cat::Cat() {
	std::cout << "This is Cat Constructor!" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
};

Cat::Cat(const Cat &other) {
	std::cout << "This is Cat Copy Constructor!" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*(other.brain));
};

Cat::~Cat() {
	std::cout << "This is Cat Destructor!" << std::endl;
	delete this->brain;
};

Cat &Cat::operator=(const Cat &other) {
	std::cout << "This is Cat Copy Assignment Operator!" << std::endl;
	if (this != &other) {
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	return (*this);
};

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
};
