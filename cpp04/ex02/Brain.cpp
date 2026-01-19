#include "Brain.hpp"

Brain::Brain() {
	std::cout << "New Brain is constructed!!" << std::endl;
};

Brain::Brain(const Brain &other) {
	std::cout << "A Brain is copy-constructed!!" <<  std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
};

Brain	&Brain::operator=(const Brain &other) {
	std::cout << "A Brain is copy-assigned!!" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
};

Brain::~Brain() {
	std::cout << "A Brain is destructed!!" << std::endl;
};
