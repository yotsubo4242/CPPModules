#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->name = "Orianna";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << name << " is constructed." << std::endl;
};

ScavTrap::ScavTrap(const std::string name) {
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << name << " is constructed." << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) {
	*this = other;
	std::cout << "ScavTrap " << name << " is copy constructed." << std::endl;
};

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " is destructed." << std::endl;
};

ScavTrap	&ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	std::cout << "ScavTrap " << name << " is assigned." << std::endl;
	return (*this);
};

void	ScavTrap::attack(const std::string &target) {
	if (hit_points == 0) {
		std::cout << "ScavTrap " << name << " is died..." << std::endl;
		return ;
	}
	if (energy_points == 0) {
		std::cout << "ScavTrap " << name << " has no energy points to attack..." << std::endl;
		return ;
	}
	energy_points--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
};

void	ScavTrap::guardGate() {
	if (hit_points == 0) {
		std::cout << "ScavTrap " << name << " is died..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
};
