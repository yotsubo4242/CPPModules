#ifndef HUMAN_B_H
# define HUMAN_B_H

#include <Weapon.hpp>
#include <iostream>

class HumanB {
	public:
		HumanB(std::string name) {
			this->name = name;
			this->weapon = NULL;
		};
		void	attack();
		void	setWeapon(Weapon &weapon);

	private:
		std::string	name;
		Weapon		*weapon;
};

#endif