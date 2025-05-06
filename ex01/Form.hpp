#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const _name;
		bool _signed;
		const int	_gradeSign;
		const int	_gradeExec;
	public:
		Form();
		Form(const std::string& name, int gradeSign, int gradeExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string& getName() const;
		bool isSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(const Bureaucrat& bureaucrat);

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
};

std::ostream& operator<<(std::ostream& os, const Form& form);


#endif