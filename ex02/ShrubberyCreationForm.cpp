/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:47:01 by anschmit          #+#    #+#             */
/*   Updated: 2025/05/07 17:47:04 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action()
{
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile.is_open())
	throw std::runtime_error("Could not open file for writing!\n");
	
	for (int i = 0; i < 3; i++)
	{
		outfile << "[Tree " << i + 1 << "]\n";
		outfile << "  *\n" << " ***\n" << "*****\n" << "  |\n\n";
	}
}