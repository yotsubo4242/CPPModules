#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("") {
	std::cout << "This is WrongAnimal Constructor!" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	this->type = other.type;
	std::cout << "This is WrongAnimal Copy Constructor!" << std::endl;
};

WrongAnimal::~WrongAnimal() {
	std::cout << "This is WrongAnimal Destructor!" << std::endl;
};

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "This is WrongAnimal Copy Assignment Operator!" << std::endl;
	return (*this);
};

void	WrongAnimal::makeSound() const {
	std::cout << "[13:34] WrongAnimal(garen): Demaciaaaaaaaaaaa" << std::endl;
};

std::string	WrongAnimal::getType() const {
	return (this->type);
}
