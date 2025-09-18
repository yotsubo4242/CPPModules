#include <iostream>

class Zombie {
	public: 
		void	announce(void);
		void	setName(std::string name);
		Zombie() {
			std::cout << "\033[31m Hi! I'm new zombieeeeee. \033[m" << std::endl;
		}
		~Zombie() {
			std::cout << "destructed zombie's name is " << this->name << std::endl;
		};
	
	private:
		std::string	name;
};
