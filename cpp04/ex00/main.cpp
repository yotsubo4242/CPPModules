#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongDog.hpp>
#include <WrongCat.hpp>

int	main(void) {
	Animal	pikachu;
	Cat		tama;
	Dog		pochi;

	pikachu.makeSound();
	tama.makeSound();
	pochi.makeSound();
	return (0);
}

// int	main(void) {
// 	WrongAnimal	garen;
// 	WrongAnimal *nasus = new WrongDog();
// 	WrongAnimal *yuumi = new WrongCat();

// 	nasus->makeSound();
// 	yuumi->makeSound();
// 	garen.makeSound();
// 	return (0);
// }
