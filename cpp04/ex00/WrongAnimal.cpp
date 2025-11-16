#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal() {
	this->type = "";
	std::cout << "This is WrongAnimal Constructor!" << std::endl;
};

WrongAnimal::~WrongAnimal() {
	std::cout << "This is WrongAnimal Destructor!" << std::endl;
};

void	WrongAnimal::makeSound() {
	std::cout << "[13:34] WrongAnimal(garen): Demaciaaaaaaaaaaa" << std::endl;
};
