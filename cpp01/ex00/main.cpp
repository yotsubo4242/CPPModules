#include <Zombie.hpp>
#include <iostream>

Zombie *newZombie(std::string);
void randomChump( std::string);

int	main(void)
{
	std::string	name;

	std::cout << "\033[33m Test1: newZombie() function\033[m" << std::endl;
	std::cout << "\033[34m please input zombie name.\033[m" << std::endl;
	std::cin >> name;
	std::cin.clear();
	Zombie *zombie = newZombie(name);
	if (zombie == NULL)
		return (1);

	std::cout << "\033[33m Test2: announce() function \033[m" << std::endl;
	zombie->announce();

	std::cout << "\033[33m Test3: destructor \033[m" << std::endl;
	delete zombie;
	
	std::cout << "\033[33m Test4: randomChump() \033[m" << std::endl;
	randomChump("taro");

	return (0);
}
