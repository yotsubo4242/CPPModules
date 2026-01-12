#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {
	public:
		Weapon(std::string type) {
			this->type = type;
		};
		const std::string&	getType();
		void				setType(std::string type);

	private:
		std::string		type;
};

#endif