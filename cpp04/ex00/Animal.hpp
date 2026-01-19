#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
		Animal	&operator=(const Animal &other);
		virtual void	makeSound() const;
		std::string	getType() const;
	protected:
		std::string	type;
};

#endif
