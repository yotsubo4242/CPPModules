#include <string>
#include <iostream>
#include <PhoneBook.hpp>

void	PhoneBook::addCmd() {
	this->contacts[target_index].addContact();
	this->target_index++;
	if (this->target_index > 7)
		this->target_index = 0;
	return ;
}

void	PhoneBook::searchCmd() {
	size_t	index;
	size_t	target_index;

	index = 0;
	for (index; index < 8 && this->contacts[index].getIsEmpty() == false; index++) {
		this->contacts[index].displayOverview(index);
	}

	std::cout << "\033[33m plese choose target index. \033[m" << std::endl;
	std::cin >> target_index;
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
	return ;
}
