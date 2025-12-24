#include <string>
#include <iostream>
#include <cstdlib>
#include <PhoneBook.hpp>

bool	is_validated_index(std::string str) {
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

void	PhoneBook::addCmd() {
	this->contacts[cur_index].addContact();
	this->cur_index++;
	if (this->cur_index > 7)
		this->cur_index = 0;
	return ;
}

void	PhoneBook::searchCmd() {
	size_t		index;
	std::string	target_index_str;
	size_t		target_index;

	for (index = 0; index < 8; index++) {
		if (this->contacts[index].getIsEmpty() == true)
			break ;
		this->contacts[index].displayOverview(index);
	}

	// Todo: SEARCH test などで無限ループする.
	std::cout << "\033[33m plese choose target index. \033[m" << std::endl;
	if (std::getline(std::cin, target_index_str) == 0)
		std::exit(1);
	if (!is_validated_index(target_index_str))
	{
		std::cout << "\033[31m error: plese input number only\033[m" << std::endl;
		return ;
	}
	target_index = atoi(target_index_str.c_str());
	if (target_index < 0 || target_index >= index || target_index > 7) {
		std::cout << "\033[31m error: target index is out of range. \033[m" << std::endl;
		return ;
	}

	this->contacts[target_index].displayDetails();
	return ;
}

void	PhoneBook::exitCmd() {
	std::exit(0);
}

void	PhoneBook::execCmds(std::string	cmd) {
	if (cmd == "ADD")
		this->addCmd();
	else if (cmd == "SEARCH")
		this->searchCmd();
	else if (cmd == "EXIT")
		this->exitCmd();
	else
		std::cout << "\033[31m error: undifined command \33[m" << std::endl;
	return ;
}
