#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <Weapon.hpp>
#include <iostream>

class HumanA {
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack();

	private:
		std::string	name;
		Weapon		&weapon;
};

#endif