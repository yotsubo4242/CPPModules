#include <WrongCat.hpp>

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "This is WrongCat Constructor!" << std::endl;
};

WrongCat::~WrongCat() {
	std::cout << "This is WrongCat Destructor!" << std::endl;
};

void	WrongCat::makeSound() {
	std::cout << "[13:04] WrongCat(yuumi): 0/10/0 gg 15 ff" << std::endl;
};
