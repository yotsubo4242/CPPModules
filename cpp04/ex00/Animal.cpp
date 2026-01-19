#include "Animal.hpp"

Animal::Animal(): type("") {
	std::cout << "This is Animal Constructor!" << std::endl;
};

Animal::Animal(const Animal &other) {
	this->type = other.type;
	std::cout << "This is Animal Copy Constructor!" << std::endl;
};

Animal::~Animal() {
	std::cout << "This is Animal Destructor!" << std::endl;
};

Animal	&Animal::operator=(const Animal &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "This is Animal Copy Assignment Operator!" << std::endl;
	return (*this);
};

void	Animal::makeSound() const {
	std::cout << "pikapika" << std::endl;
};

std::string	Animal::getType() const {
	return (this->type);
}
