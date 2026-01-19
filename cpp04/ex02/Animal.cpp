#include "Animal.hpp"

Animal::Animal() {
	std::cout << "This is Animal Constructor!" << std::endl;
	this->type = "";
};

Animal::Animal(const Animal &other) {
	std::cout << "This is Animal Copy Constructor!" << std::endl;
	this->type = other.type;
};

Animal::~Animal() {
	std::cout << "This is Animal Destructor!" << std::endl;
};

Animal	&Animal::operator=(const Animal &other) {
	std::cout << "This is Animal Copy Assignment Operator!" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
};

std::string	Animal::getType() const {
	return (this->type);
};
