#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
	public:
		Animal();
		~Animal();
		virtual	void	makeSound();
	protected:
		std::string	type;
};

#endif
