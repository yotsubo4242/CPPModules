#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;
		void beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
