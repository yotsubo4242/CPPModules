#include <Weapon.hpp>

Weapon::Weapon(std::string type): type(type){};

const std::string&	Weapon::getType() {
	std::string &res = this->type;
	return (res);
};

void	Weapon::setType(std::string type) {
	this->type = type;
	return ;
};
