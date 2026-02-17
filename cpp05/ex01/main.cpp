#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << GREEN << "Test 1: Success Case" << RES << std::endl;
	std::cout << "↓------------------------------↓" << std::endl;
	try
	{
		Bureaucrat b1("B1", 1);
		Form f1("F1", 1, 1);
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n" << GREEN << "Test 2: Grade Too Low Case" << RES << std::endl;
	std::cout << "↓------------------------------↓" << std::endl;
	try
	{
		Bureaucrat b2("B2", 150);
		Form f2("F2", 1, 1);
		b2.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n" << GREEN << "Test 3: Grade High Case" << RES << std::endl;
	std::cout << "↓------------------------------↓" << std::endl;
	try
	{
		Bureaucrat b3("B3", 1);
		Form f3("F3", 150, 150);
		b3.signForm(f3);
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n" << GREEN << "Test 4: Invalid Form Creation Case (grade is too high)" << RES << std::endl;
	std::cout << "↓------------------------------↓" << std::endl;
	try
	{
		Form f4("F4", 0, 1);
		std::cout << f4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n" << GREEN << "Test 5: Invalid Form Creation Case (grade is too low)" << RES << std::endl;
	std::cout << "↓------------------------------↓" << std::endl;
	try
	{
		Form f5("F5", 1, 151);
		std::cout << f5 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
