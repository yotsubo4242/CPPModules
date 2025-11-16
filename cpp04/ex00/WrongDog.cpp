#include <WrongDog.hpp>

WrongDog::WrongDog() {
	this->type = "WrongDog";
	std::cout << "This is WrongDog Constructor!" << std::endl;
};

WrongDog::~WrongDog() {
	std::cout << "This is WrongDog Destructor!" << std::endl;
};

void	WrongDog::makeSound() {
	std::cout << "[12:41] WrongDog(Nusas): jg gap" << std::endl;
};
