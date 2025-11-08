#include <ScavTrap.hpp>

ScavTrap::ScavTrap() {
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " is constructed." << std::endl;
};

ScavTrap::ScavTrap(const std::string name) {
	this->name = name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " is constructed." << std::endl;
};

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " is destructed." << std::endl;
};

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
};
