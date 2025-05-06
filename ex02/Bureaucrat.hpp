/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anna <anna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:13:31 by anschmit          #+#    #+#             */
/*   Updated: 2025/05/06 14:37:53 by anna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define PINK "\033[36m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"
#include <iostream>
#include <ostream>

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		const std::string getName() const;
		int getGrade() const;	
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc);

#endif
