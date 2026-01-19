#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);
		void	makeSound() const;
	private:
		Brain	*brain;
};

#endif
