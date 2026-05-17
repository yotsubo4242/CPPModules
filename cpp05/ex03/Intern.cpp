#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern& Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

FormType Intern::getFormType(const std::string &formName) {
	if (formName == "shrubbery creation")
		return SHRUBBERY;
	else if (formName == "robotomy request")
		return ROBOTOMY;
	else if (formName == "presidential pardon")
		return PRESIDENTIAL;
	else
		return UNKNOWN;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	FormType type = getFormType(formName);
	AForm *(Intern::*formCreators[])(const std::string&) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	AForm *form = NULL;
	if (type == UNKNOWN) {
		std::cout << RED "Intern couldn't create form: unknown form type '" << formName << "'" << RES << std::endl;
		return NULL;
	}
	form = (this->*formCreators[type])(target);
	std::cout << GREEN "Intern creates " << form->getName() << RES << std::endl;
	return form;
}