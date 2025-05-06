/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anna <anna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:44:17 by anschmit          #+#    #+#             */
/*   Updated: 2025/05/06 14:34:15 by anna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAAForm.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :_name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}
void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = _grade - 1;	
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = _grade + 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return ("\033[35mGrade too high\033[0m");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("\033[35mGrade too low\033[0m");
}

void Bureaucrat::signAForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bc)
{
	std::cout << BLUE << bc.getName() << RESET << ", bureaucrat grade " << GREEN << bc.getGrade() << RESET << std::endl;
	return os;
}