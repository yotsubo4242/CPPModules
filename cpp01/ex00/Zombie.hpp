#include <iostream>

class Zombie {
	public: 
		void	announce(void);
		Zombie(std::string name) {
			this->name = name;
		}
		~Zombie() {
			std::cout << "destructed zombie's name is " << this->name << std::endl;
		};
	
	private:
		std::string	name;
};
