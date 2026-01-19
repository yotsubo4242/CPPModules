#include "Dog.hpp"
#include "Cat.hpp"

# define ANIMAL_NUM 4

int	main(void) {
	Animal	*Animals[ANIMAL_NUM];

	for (int i = 0; i < ANIMAL_NUM; i++) {
		if (i % 2)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}

	for (int i = 0; i < ANIMAL_NUM; i++) {
		std::cout << "------------------------" << std::endl;
		std::cout << "Animal " << i << " is a " << Animals[i]->getType() << "." << std::endl;
		Animals[i]->makeSound();
		delete Animals[i];
		std::cout << std::endl;
	}

	Dog	basic;
	{
		Dog	tmp = basic;
	}

	//Animal	tmp;

	return (0);
}
