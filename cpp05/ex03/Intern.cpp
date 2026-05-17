#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

FormType Intern::getFormType(const std::string& formName) {
	if (formName == "shrubbery creation")
		return SHRUBBERY;
	if (formName == "robotomy request")
		return ROBOTOMY;
	if (formName == "presidential pardon")
		return PRESIDENTIAL;
	return UNKNOWN;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	AForm *form = NULL;
	switch (getFormType(formName)) {
		case SHRUBBERY:
			form = new ShrubberyCreationForm(target);
			break;
		case ROBOTOMY:
			form = new RobotomyRequestForm(target);
			break;
		case PRESIDENTIAL:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << RED "Error: Intern cannot create " << formName << " because it's unknown." << RES << std::endl;
			return NULL;
	}
	std::cout << GREEN "Intern creates " << formName << RES << std::endl;
	return form;
}
