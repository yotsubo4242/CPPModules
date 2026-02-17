#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("jhon"), _grade(150)
{
	std::cout << YELLOW "Bureaucrat default constructor called" RES << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << YELLOW "Bureaucrat parameterized constructor called" RES << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << YELLOW "Bureaucrat copy constructor called" RES << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << YELLOW "Bureaucrat destructor called" RES << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << YELLOW "Bureaucrat copy assignment operator called" RES << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
