		
#include "Form.hpp"
		
Form::Form() : _name("Default"), _signed(false), _gradeSign(150), _gradeExec(150) {}

Form::Form(const std::string& name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

Form &Form::operator=(const Form &other) 
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

const std::string& Form::getName() const { return (_name); }
bool Form::isSigned() const { return (_signed); }
int Form::getGradeSign() const { return (_gradeSign); }
int Form::getGradeExec() const { return (_gradeExec); }

const char* Form::GradeTooHighException::what() const throw()
{
	return("\033[31mGrade too high\033[0m");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("\033[31mGrade too low\033[0m");
}
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: Name: "<< BLUE << form.getName() << RESET
		<< ", Signed: " << (form.isSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form.getGradeSign() 
		<< ", Grade to execute: " << form.getGradeExec() << std::endl;
	return (os);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

Form::~Form() {}
