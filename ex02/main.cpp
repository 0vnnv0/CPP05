/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anna <anna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:37:41 by anschmit          #+#    #+#             */
/*   Updated: 2025/05/06 15:20:01 by anna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int	main()
{
	std::cout << "----------- test1 ----------" << std::endl;
	Bureaucrat bob("Bob", 10);
	Form taxes("Taxes", 20, 30);
	std::cout << taxes << std::endl;
	bob.signForm(taxes);
	std::cout << taxes << std::endl;
	
	std::cout << "----------- test2 ----------" << std::endl;
	try {
		Form tax2("Taxes2", 160, 9);
		std::cout << tax2 << std::endl;
		bob.signForm(tax2);
		std::cout << tax2 << std::endl;
	} catch(const std::exception& e)
	{
		std::cerr << "Exception caught while signing: " << e.what() << std::endl; 
	}
	return 0;
}