#ifndef WrongCat_H
# define WrongCat_H

#include <WrongAnimal.hpp>

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		~WrongCat();
		void	makeSound();
};

#endif
