#include <Zombie.hpp>

Zombie *newZombie(std::string);

void randomChump( std::string name ) {
	Zombie *tmpZombie;
	tmpZombie = newZombie(name);
	if (tmpZombie == NULL)
		return ;
	tmpZombie->announce();
	delete (tmpZombie);
}
