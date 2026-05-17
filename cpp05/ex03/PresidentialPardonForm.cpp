#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon Form", 25, 5)
{
	this->_target = "default";
	std::cout << YELLOW << "PresidentialPardonForm default constructor called" << RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon Form", 25, 5)
{
	this->_target = target;
	std::cout << YELLOW << "PresidentialPardonForm constructor called" << RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other)
{
	this->_target = other._target;
	std::cout << YELLOW << "PresidentialPardonForm copy constructor called" << RES << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << YELLOW << "PresidentialPardonForm copy assignment operator called" << RES << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << YELLOW << "PresidentialPardonForm destructor called" << RES << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox" << RES << std::endl;
}
