#include <string>
#include <iostream>
#include <iomanip>
#include <Contact.hpp>
#include <stdlib.h>

bool	is_validated_phone_number(std::string str) {
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

void	Contact::addContact() {
	std::cout << "\033[33m ADD command executing... \033[m" << std::endl;

	do {
		std::cout << "plese enter your first name." << std::endl;
		if (std::getline(std::cin, this->first_name) == 0)
			exit(1);
	} while (this->first_name.empty());

	do {
		std::cout << "plese enter your last name." << std::endl;
		if (std::getline(std::cin, this->last_name) == 0)
			exit(1);
	} while (this->last_name.empty());
	do {
		std::cout << "plese enter your nick name." << std::endl;
		if (std::getline(std::cin, this->nick_name) == 0)
			exit(1);
	} while (this->nick_name.empty());
	
	do {
		std::cout << "plese enter your phone number." << std::endl;
		if (std::getline(std::cin, this->phone_number) == 0)
			exit(1);
	} while (this->phone_number.empty() || !is_validated_phone_number(this->phone_number));

	do {
		std::cout << "plese enter your darkest secret." << std::endl;
		if (std::getline(std::cin, this->darkest_secret) == 0)
			exit(1);
	} while (this->darkest_secret.empty());
	this->is_empty = false;

	std::cout << "\033[32m add a new contact successfully \033[m" << std::endl;
	return ;
}

bool	Contact::getIsEmpty() {
	return (this->is_empty);
}

void	Contact::displayOverview(size_t index) {
	std::cout << std::setw(10) << std::right << index << '|';
	if (this->first_name.length() > 10)
		std::cout << std::setw(10) << std::right << this->first_name.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << std::right << this->first_name;
	std::cout << '|';

	if (this->last_name.length() > 10)
		std::cout << std::setw(10) << std::right << this->last_name.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << std::right << this->last_name;
	std::cout << '|';

	if (this->nick_name.length() > 10)
		std::cout << std::setw(10) << std::right << this->nick_name.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << std::right << this->nick_name;
	std::cout << '|' << std::endl;
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
