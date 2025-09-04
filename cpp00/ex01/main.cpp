#include <iostream>
#include <PhoneBook.hpp>

int	main(void)
{
	PhoneBook	phone_book;
	std::string	cmd;

	while (1)
		phone_book.execCmds(cmd);
	return (0);
}
