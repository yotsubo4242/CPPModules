#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "This is WrongCat Constructor!" << std::endl;
};

WrongCat::WrongCat(const WrongCat &other) {
	this->type = other.type;
	std::cout << "This is WrongCat Copy Constructor!" << std::endl;
};

WrongCat::~WrongCat() {
	std::cout << "This is WrongCat Destructor!" << std::endl;
};

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "This is WrongCat Copy Assignment Operator!" << std::endl;
	return (*this);
};

void	WrongCat::makeSound() const {
	std::cout << "[13:04] WrongCat(yuumi): 0/10/0 gg 15 ff" << std::endl;
};
