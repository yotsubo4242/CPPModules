#ifndef PHONE_BOOK
#define PHONE_BOOK

#include <iostream>
#include <string>
#include <Contact.hpp>

class PhoneBook {
	public:
		void	execCmds(std::string commands);

	private:
		Contact	contacts[8];

		void	addCmd();
		void	searchCmd();
		void	exitCmd();
};

#endif
