/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anna <anna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:37:41 by anschmit          #+#    #+#             */
/*   Updated: 2025/05/05 18:40:21 by anna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "--------> 1. test" << std::endl;
	Bureaucrat bob("Bob", 42);
	std::cout << bob;
	
	std::cout << "--------> 2. test" << std::endl;
	bob.decrementGrade();
	std::cout << bob;
	bob.incrementGrade();
	bob.incrementGrade();
	bob.incrementGrade();
	std::cout << bob;
	
	std::cout << "--------> 3. test" << std::endl;
	Bureaucrat Klaus("Klaus", 1);
	try 
	{
		std::cout << Klaus;
		Klaus.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		std::cout << "--------> 4. test" << std::endl;

	try
	{
		Bureaucrat Olaf("Olaf", 0);
		std::cout << Olaf << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------> 5. test" << std::endl;
	try
	{		
		Bureaucrat bernd("Bernd", 2999);
		std::cout << bernd;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;	
	}
	
	return 0;
}