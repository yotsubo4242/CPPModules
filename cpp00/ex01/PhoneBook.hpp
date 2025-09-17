#ifndef PHONE_BOOK
#define PHONE_BOOK

#include <iostream>
#include <string>
#include <Contact.hpp>

class PhoneBook {
	public:
		PhoneBook() {
			cur_index = 0;
		};
		void	execCmds(std::string commands);

	private:
		Contact	contacts[8];
		size_t	cur_index;

		void	addCmd();
		void	searchCmd();
		void	exitCmd();
};

#endif
