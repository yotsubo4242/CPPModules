#include <Harl.hpp>

int	main(void) {
	Harl	harl;

	std::cout << "\033[32m [DEBUG] \033[m" << std::endl;
	harl.complain("debug");
	std::cout << "\033[32m [INFO] \033[m" << std::endl;
	harl.complain("info");
	std::cout << "\033[32m [WARNING] \033[m" << std::endl;
	harl.complain("warning");
	std::cout << "\033[32m [ERROR] \033[m" << std::endl;
	harl.complain("error");
	return (0);
}
