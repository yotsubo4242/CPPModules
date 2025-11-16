#ifndef WrongDog_H
# define WrongDog_H

#include <WrongAnimal.hpp>

class WrongDog: public WrongAnimal {
	public:
		WrongDog();
		~WrongDog();
		void	makeSound();
};

#endif
