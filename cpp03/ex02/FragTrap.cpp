#include <FragTrap.hpp>

FragTrap::FragTrap() {
	name = "Blitzcrank";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " is constructed." << std::endl;
};

FragTrap::FragTrap(const std::string name) {
	this->name = name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " is constructed." << std::endl;
};

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " is destructed." << std::endl;
};

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " says \"High five!!\"." << std::endl;
};
