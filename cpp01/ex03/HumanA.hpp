#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <Weapon.hpp>
#include <iostream>

class HumanA {
	public:
		HumanA(std::string name, Weapon &weapon) {
			this->name = name;
			this->weapon = weapon;
		};
		void	attack();

	private:
		std::string	name;
		// Todo: これダメそう... うーーん
		Weapon		&weapon;
};

#endif