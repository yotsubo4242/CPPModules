#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern intern;
	AForm* form;

	std::cout << "--- Shrubbery Creation Form: ---" << std::endl;
	form = intern.makeForm("shrubbery creation", "home");
	if (form) {
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << std::endl;
	std::cout << "--- Robotomy Request Form: ---" << std::endl;
	form = intern.makeForm("robotomy request", "Mark");
	if (form) {
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << std::endl;
	std::cout << "--- Presidential Pardon Form: ---" << std::endl;
	form = intern.makeForm("presidential pardon", "Alice");
	if (form) {
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << std::endl;
	std::cout << "--- Unknown Form: ---" << std::endl;
	form = intern.makeForm("unknown form", "target");
	if (form) {
		std::cout << *form << std::endl;
		delete form;
	}

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