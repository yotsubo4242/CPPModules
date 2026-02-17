#include "Form.hpp"

Form::Form() :
	_name("Default Form"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << YELLOW << "Form default constructor called" << RES << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << YELLOW << "Form constructor called" << RES << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	std::cout << YELLOW << "Form copy constructor called" << RES << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << YELLOW << "Form copy assignment operator called" << RES << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << YELLOW << "Form destructor called" << RES << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool Form::isSigned() const
{
	return this->_isSigned;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form Name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}