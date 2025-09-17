#include <string>
#include <iostream>
#include <iomanip>
#include <Contact.hpp>

void	Contact::addContact() {
	std::cout << "\033[33m ADD command executing... \033[m" << std::endl;

	std::cout << "plese enter your first name." << std::endl;
	std::cin >> this->first_name;
	std::cout << "plese enter your last name." << std::endl;
	std::cin >> this->last_name;
	std::cout << "plese enter your nick name." << std::endl;
	std::cin >> this->nick_name;
	std::cout << "plese enter your phone number." << std::endl;
	std::cin >> this->phone_number;
	std::cout << "plese enter your darkest secret." << std::endl;
	std::cin >> this->darkest_secret;

	this->is_empty = false;
	std::cout << "\033[32m add a new contact successfully \033[m" << std::endl;
	return ;
}

bool	Contact::getIsEmpty() {
	return (this->is_empty);
}

void	Contact::displayOverview(size_t index) {
	std::cout << std::setw(10) << std::right << index << '|';
	std::cout << std::setw(10) << std::right << this->first_name << '|';
	std::cout << std::setw(10) << std::right << this->last_name << '|';
	std::cout << std::setw(10) << std::right << this->nick_name << std::endl;
	return ;
}

void	Contact::displayDetails() {
	std::cout << "\33[33m here is details \33[m" << std::endl;

	std::cout << "first name: " << this->first_name << std::endl;
	std::cout << "last name: " << this->last_name << std::endl;
	std::cout << "nick name: " << this->nick_name << std::endl;
	std::cout << "phone number: " << this->phone_number << std::endl;
	std::cout << "darkest secret: " << this->darkest_secret << std::endl;
	return ;
}
