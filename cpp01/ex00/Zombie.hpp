#include <iostream>

class Zombie {
	public: 
		void	announce(void);
		Zombie(std::string name);
		~Zombie();
	
	private:
		std::string	name;
};
