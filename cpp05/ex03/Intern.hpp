#ifndef INTERN_H
# define INTERN_H

# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

enum FormType {
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENTIAL,
	UNKNOWN
};

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		FormType getFormType(const std::string& formName);
		AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
