#include <string>
#include <iostream>
#include <PhoneBook.hpp>

Contact	

void	PhoneBook::addCmd() {

}

Contact	PhoneBook::getTargetContact() {
	
}

void	PhoneBook::execCmds(std::string	cmd) {
	Contact	target_contact;

	target_contact = this->getTargetContact();
	if (cmd == "ADD")
		this->addCmd();
	else if (cmd == "SEARCH")
		this->searchCmd();
	else if (cmd == "EXIT")
		this->exitCmd();
	return ;
}
