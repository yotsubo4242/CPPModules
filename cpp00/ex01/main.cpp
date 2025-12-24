#include <iostream>
#include <string>
#include <PhoneBook.hpp>
#include <stdlib.h>

int	main(void)
{
	PhoneBook	phone_book;
	std::string	cmd;

	while (1)
	{
		std::cout << "\033[33m plese input commands ( ADD, SEARCH, EXIT ) \033[m" << std::endl;
		if (std::getline(std::cin, cmd) == 0)
			exit(1);
		phone_book.execCmds(cmd);
	}
	return (0);
}
