#ifndef PHONE_BOOK
#define PHONE_BOOK

#include <iostream>
#include <string>
#include <Contact.hpp>

class PhoneBook {
	public:
		void	execCmds(std::string commands);

	private:
		int		contacts_num;
		Contact	contacts[8];

		void	addContact();
		void	searchContact();
		void	exit();
		Contact	getTargetContact(int target_index);
};

#endif
