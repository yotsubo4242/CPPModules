#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form", 72, 45)
{
	this->_target = "default";
	std::cout << YELLOW << "RobotomyRequestForm default constructor called" << RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request Form", 72, 45)
{
	this->_target = target;
	std::cout << YELLOW << "RobotomyRequestForm parameterized constructor called" << RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other)
{
	this->_target = other._target;
	std::cout << YELLOW << "RobotomyRequestForm copy constructor called" << RES << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << YELLOW << "RobotomyRequestForm copy assignment operator called" << RES << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << "RobotomyRequestForm destructor called" << RES << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Drilling noises... " << std::endl;
	if (std::time(0) % 2)
		std::cout << GREEN << "Success: " << _target << " has been robotomized." << RES << std::endl;
	else
		std::cout << RED << "Failure: " << _target << " could not be robotomized." << RES << std::endl;
}
