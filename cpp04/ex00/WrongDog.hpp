#ifndef WrongDog_H
# define WrongDog_H

#include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal {
	public:
		WrongDog();
		WrongDog(const WrongDog &other);
		~WrongDog();
		WrongDog &operator=(const WrongDog &other);
		void	makeSound() const;
};

#endif
