#include <iostream>
#include <PhoneBook.hpp>

int	main(void)
{
	PhoneBook	phone_book;
	std::string	cmd;

	while (1)
	{
		std::cout << "\033[33m plese input commands ( ADD, SEARCH, EXIT ) \033[m" << std::endl;
		std::getline(std::cin, cmd);
		std::cin.clear();
		phone_book.execCmds(cmd);
	}
	return (0);
}
