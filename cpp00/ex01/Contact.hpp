#ifndef CONTACT
#define CONTACT

#include <iostream>
#include <string>

class Contact {
	public:
		Contact() {
			this->is_empty = true;
		};
		void	addContact();
		bool	getIsEmpty();
		void	displayOverview(size_t index);
		void	displayDetails();

	private:
		std::string	first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
		bool		is_empty;
};

#endif
