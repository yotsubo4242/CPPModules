#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

//int main()
//{
//	const Animal* meta = new Animal();
//	const Animal* i = new Cat();
//	const Animal* j = new Dog();
//	std::cout << i->getType() << " " << std::endl;
//	std::cout << j->getType() << " " << std::endl;
//	i->makeSound(); //will output the cat sound!
//	j->makeSound();
//	meta->makeSound();
//
//	delete meta;
//	delete j;
//	delete i;
//	return 0;
//}

int main()
{
	const WrongAnimal* garen = new WrongAnimal();
	const WrongCat* yuumi1 = new WrongCat();
	const WrongAnimal* nasus = new WrongDog();
	const WrongAnimal* yuumi2 = new WrongCat();
	std::cout << yuumi2->getType() << " " << std::endl;
	std::cout << nasus->getType() << " " << std::endl;
	yuumi1->makeSound();
	yuumi2->makeSound(); //will output the cat sound!
	nasus->makeSound();
	garen->makeSound();

	delete garen;
	delete nasus;
	delete yuumi1;
	delete yuumi2;
	return 0;
}
