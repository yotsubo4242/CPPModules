#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &other);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
};

#endif
