#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << BLUE << "--- Constructors ---\n" << RES << std::endl;
	//Bureaucrat b("President", 150); // for ShrubberyCreationForm
	//Bureaucrat b("President", 145); // for ShrubberyCreationForm
	//Bureaucrat b("President", 137); // for ShrubberyCreationForm

	//Bureaucrat b("President", 100); // for RobotomyRequestForm
	//Bureaucrat b("President", 72); // for RobotomyRequestForm
	//Bureaucrat b("President", 45); // for RobotomyRequestForm


	//Bureaucrat b("President", 30); // for PresidentialPardonForm
	//Bureaucrat b("President", 25); // for PresidentialPardonForm
	Bureaucrat b("President", 5); // for PresidentialPardonForm
	ShrubberyCreationForm s("Home");
	RobotomyRequestForm r("John");
	PresidentialPardonForm p("Alice");


	std::cout << BLUE << "\n--- Signing Forms ---\n" << RES << std::endl;
	try {
		b.signForm(s);
	} catch (std::exception& e) {
		std::cerr << RED << "Error signing form: " << e.what() << RES << std::endl;
	}
	try {
		b.signForm(r);
	} catch (std::exception& e) {
		std::cerr << RED << "Error signing form: " << e.what() << RES << std::endl;
	}
	try {
		b.signForm(p);
	} catch (std::exception& e) {
		std::cerr << RED << "Error signing form: " << e.what() << RES << std::endl;
	}

	std::cout << BLUE << "\n--- Executing ShrubberyCreationForm ---\n" << RES << std::endl;
	try {
		s.execute(b);
	} catch (std::exception& e) {
		std::cerr << RED << "Error executing form: " << e.what() << RES << std::endl;
	}
	std::cout << BLUE << "\n--- Executing RobotomyRequestForm ---\n" << RES << std::endl;
	try {
		r.execute(b);
	} catch (std::exception& e) {
		std::cerr << RED << "Error executing form: " << e.what() << RES << std::endl;
	}
	std::cout << BLUE << "\n--- Executing PresidentialPardonForm ---\n" << RES << std::endl;
	try {
		p.execute(b);
	} catch (std::exception& e) {
		std::cerr << RED << "Error executing form: " << e.what() << RES << std::endl;
	}

	std::cout << BLUE << "\n--- Destructors ---\n" << RES << std::endl;

	return 0;
}

/*
ShrubberyCreation:
- Grade to sign: 145
- Grade to execute: 137
testcase:
	150, 145, 137

RobotomyRequest:
- Grade to sign: 72
- Grade to execute: 45
testcase:
	100, 72, 45

PresidentialPardon:
- Grade to sign: 25
- Grade to execute: 5
testcase:
	30, 25, 5

*/