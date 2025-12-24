#include <Dog.hpp>
#include <Cat.hpp>

# define ANIMAL_NUM 4

int	main(void) {
	Animal	*Animals[ANIMAL_NUM];

	for (int i = 0; i < ANIMAL_NUM; i++) {
		if (i % 2)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}

	for (int j = 0; j < ANIMAL_NUM; j++)
		delete	Animals[j];

	return (0);
}
