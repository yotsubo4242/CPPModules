#include <ClapTrap.hpp>

ClapTrap::ClapTrap() {
	name = "Orianna";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
};

ClapTrap::ClapTrap(const std::string name) {
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "ClapTrap " << this->name << " constructed." << std::endl;
};

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructed." << std::endl;
};

void	ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl; 
};

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << " took " << amount << " damages..." << std::endl; 
};

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << " be repaired and gain " << amount << " HP!" << std::endl;
};
