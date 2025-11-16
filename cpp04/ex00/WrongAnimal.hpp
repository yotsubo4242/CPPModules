#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		~WrongAnimal();
		void	makeSound();
	protected:
		std::string	type;
};

#endif
