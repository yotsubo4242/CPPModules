#include <Dog.hpp>

Dog::Dog() {
	this->type = "dog";
	std::cout << "This is Dog Constructor!" << std::endl;
};

Dog::~Dog() {
	std::cout << "This is Dog Destructor!" << std::endl;
};

void	Dog::makeSound() {
	std::cout << "Woof" << std::endl;
};
