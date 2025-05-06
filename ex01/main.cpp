/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anna <anna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:37:41 by anschmit          #+#    #+#             */
/*   Updated: 2025/05/05 19:08:09 by anna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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