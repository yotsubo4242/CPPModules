#include <string>
#include <iostream>
#include <cstdlib>
#include <PhoneBook.hpp>

void	PhoneBook::addCmd() {
	this->contacts[cur_index].addContact();
	this->cur_index++;
	if (this->cur_index > 7)
		this->cur_index = 0;
	return ;
}

void	PhoneBook::searchCmd() {
	size_t	index;
	size_t	target_index;

	for (index = 0; index < 8; index++) {
		if (this->contacts[index].getIsEmpty() == true)
			break ;
		this->contacts[index].displayOverview(index);
	}

	// Todo: SEARCH test などで無限ループする.
	std::cout << "\033[33m plese choose target index. \033[m" << std::endl;
	std::cin >> target_index;
	std::cin.clear();
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
