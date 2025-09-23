#include <Harl.hpp>

void	Harl::complain(std::string level) {
	std::string	level_strs[] = {"debug", "info", "warning", "error"};
	void	(Harl::*operation[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	size_t	i = 0;
	
	while (i < 4) {
		if (level == level_strs[i])
			break ;
		i++;
	}
	if (i == 4)
		std::cerr << "Error: no function much." << std::endl;
	else
		(this->*operation[i])();
	return ;
};

void	Harl::debug(void) {
	std::cout << DEBUG_MSG << std::endl;
};

void	Harl::info(void) {
	std::cout << INFO_MSG << std::endl;
};

void	Harl::warning(void) {
	std::cout << WARNING_MSG << std::endl;
};

void	Harl::error(void) {
	std::cout << ERROR_MSG << std::endl;
};
