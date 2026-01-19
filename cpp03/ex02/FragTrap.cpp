#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->name = "Blitzcrank";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << name << " is constructed." << std::endl;
};

FragTrap::FragTrap(const std::string name) {
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << this->name << " is constructed." << std::endl;
};

FragTrap::FragTrap(const FragTrap &other) {
	*this = other;
	std::cout << "FragTrap " << name << " is copy constructed." << std::endl;
};

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " is destructed." << std::endl;
};

FragTrap	&FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	std::cout << "FragTrap " << name << " is assigned." << std::endl;
	return (*this);
};

void	FragTrap::highFivesGuys() {
	if (hit_points == 0) {
		std::cout << "FragTrap " << name << " is died..." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " says \"High five!!\"." << std::endl;
};
