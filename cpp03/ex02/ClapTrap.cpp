#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Orianna"), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
};

ClapTrap::ClapTrap(const std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << this->name << " constructed." << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "ClapTrap " << this->name << " copy constructed." << std::endl;
};

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructed." << std::endl;
};

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	std::cout << "ClapTrap " << this->name << " assigned." << std::endl;
	return (*this);
};

void	ClapTrap::attack(const std::string &target) {
	if (hit_points == 0) {
		std::cout << "ClapTrap " << this->name << " is died..." << std::endl;
		return ;
	}
	if (energy_points == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy..." << std::endl;
		return ;
	}
	energy_points--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl; 
};

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << " took " << amount << " damages..." << std::endl;
	if (hit_points == 0 || hit_points < amount) {
		hit_points = 0;
		std::cout << "ClapTrap " << this->name << " is died..." << std::endl;
		return ;
	}
	hit_points -= amount;
};

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hit_points == 0) {
		std::cout << "ClapTrap " << this->name << " is died..." << std::endl;
		return ;
	}
	if (energy_points == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy..." << std::endl;
		return ;
	}
	energy_points--;
	hit_points += amount;
	std::cout << "ClapTrap " << this->name << " be repaired and gain " << amount << " HP!" << std::endl;
};
