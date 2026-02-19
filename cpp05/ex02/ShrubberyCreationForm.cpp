#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "default";
	std::cout << YELLOW << "ShrubberyCreationForm default constructor called" << RES << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << YELLOW << "ShrubberyCreationForm parameterized constructor called" << RES << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	this->_target = other._target;
	std::cout << YELLOW << "ShrubberyCreationForm copy constructor called" << RES << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << YELLOW << "ShrubberyCreationForm copy assignment operator called" << RES << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << YELLOW << "ShrubberyCreationForm destructor called" << RES << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream outFile((_target + "_shrubbery").c_str());
	if (!outFile.is_open())
	{
		std::cerr << RED << "Error: Could not create file " << _target + "_shrubbery" << RES << std::endl;
		return;
	}

	outFile << "       _-_" << std::endl;
	outFile << "    /~~   ~~\\" << std::endl;
	outFile << " /~~         ~~\\" << std::endl;
	outFile << "{               }" << std::endl;
	outFile << " \\  _-     -_  /" << std::endl;
	outFile << "   ~  \\\\ //  ~" << std::endl;
	outFile << "_- -   | | _- _" << std::endl;
	outFile << "  _ -  | |   -_" << std::endl;
	outFile << "      // \\\\" << std::endl;

	outFile.close();
	std::cout << GREEN << "Shrubbery created successfully in " << _target + "_shrubbery" << RES << std::endl;
}