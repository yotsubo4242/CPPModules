#include "AForm.hpp"

AForm::AForm() :
	_name("Default AForm"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << YELLOW << "AForm default constructor called" << RES << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << YELLOW << "AForm constructor called" << RES << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	std::cout << YELLOW << "AForm copy constructor called" << RES << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << YELLOW << "AForm copy assignment operator called" << RES << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << YELLOW << "AForm destructor called" << RES << std::endl;
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool AForm::isSigned() const
{
	return this->_isSigned;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm Name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}