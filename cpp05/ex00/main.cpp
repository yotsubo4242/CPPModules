#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << GREEN "Test for incrementGrade and decrementGrade" RES << std::endl;
	std::cout << GREEN "case: Bureaucrat a(\"a\", 1); a.incrementGrade();" RES << std::endl;
	std::cout << "↓↓↓" << std::endl;
	try
	{
		Bureaucrat a("a", 1);
		std::cout << a.getName() << ", " << a.getGrade() << std::endl;
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << GREEN "case: Bureaucrat b(\"b\", 150); b.decrementGrade();" RES << std::endl;
	std::cout << "↓↓↓" << std::endl;
	try
	{
		Bureaucrat b("b", 150);
		std::cout << b.getName() << ", " << b.getGrade() << std::endl;
		b.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << GREEN "Test for constructor" RES << std::endl;
	std::cout << GREEN "case: Bureaucrat c(\"c\", 0);" RES << std::endl;
	std::cout << "↓↓↓" << std::endl;
	try
	{
		Bureaucrat c("c", 0);
		std::cout << c.getName() << ", " << c.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << GREEN "case: Bureaucrat d(\"d\", 151);" RES << std::endl;
	std::cout << "↓↓↓" << std::endl;

	try
	{
		Bureaucrat d("d", 151);
		std::cout << d.getName() << ", " << d.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << GREEN "Test for out stream" RES << std::endl;
	std::cout << "↓↓↓" << std::endl;

	Bureaucrat e("e", 75);
	std::cout << e << std::endl;

	return 0;
}