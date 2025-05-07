/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:47:19 by anschmit          #+#    #+#             */
/*   Updated: 2025/05/07 17:47:21 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
		
AForm::AForm() : _name("Default"), _signed(false), _gradeSign(150), _gradeExec(150) {}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

AForm &AForm::operator=(const AForm &other) 
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

const std::string& AForm::getName() const { return (_name); }
bool AForm::isSigned() const { return (_signed); }
int AForm::getGradeSign() const { return (_gradeSign); }
int AForm::getGradeExec() const { return (_gradeExec); }

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("\033[31mForm not signed!\033[0m");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("\033[31mGrade too high\033[0m");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("\033[31mGrade too low\033[0m");
}
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: Name: "<< BLUE << form.getName() << RESET
		<< ", Signed: " << (form.isSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form.getGradeSign() 
		<< ", Grade to execute: " << form.getGradeExec() << std::endl;
	return (os);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::performExecute(Bureaucrat const &executor)
{
	if (!this->isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
}

AForm::~AForm() {}
