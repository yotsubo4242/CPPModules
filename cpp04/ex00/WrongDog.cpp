#include "WrongDog.hpp"

WrongDog::WrongDog() {
	this->type = "WrongDog";
	std::cout << "This is WrongDog Constructor!" << std::endl;
};

WrongDog::WrongDog(const WrongDog &other) {
	this->type = other.type;
	std::cout << "This is WrongDog Copy Constructor!" << std::endl;
};

WrongDog::~WrongDog() {
	std::cout << "This is WrongDog Destructor!" << std::endl;
};

WrongDog &WrongDog::operator=(const WrongDog &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "This is WrongDog Copy Assignment Operator!" << std::endl;
	return (*this);
};

void	WrongDog::makeSound() const {
	std::cout << "[12:41] WrongDog(Nasus): jg gap" << std::endl;
};
