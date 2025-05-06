#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		const int	_gradeSign;
		const int	_gradeExec;
	public:
		AForm();
		AForm(const std::string& name, int gradeSign, int gradeExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		virtual const std::string& getName() const;
		bool isSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void performExecute(Bureaucrat const &executor);

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

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

std::ostream& operator<<(std::ostream& os, const AForm& form);


#endif