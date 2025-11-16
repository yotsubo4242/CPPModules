#include <Animal.hpp>

Animal::Animal() {
	this->type = "";
	std::cout << "This is Animal Constructor!" << std::endl;
};

Animal::~Animal() {
	std::cout << "This is Animal Destructor!" << std::endl;
};
