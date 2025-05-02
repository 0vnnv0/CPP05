/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:37:41 by anschmit          #+#    #+#             */
/*   Updated: 2025/05/02 15:57:38 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat bob("Bob", 42);
	std::cout << "Bureaucrat Bob created" << std::endl;
	bob.decrementGrade();
	std::cout << bob.getGrade() << std::endl;
	Bureaucrat Klaus("Klaus", 1);
	try {
	Klaus.incrementGrade();
	std::cout << Klaus.getGrade() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "idk" << std::endl;
	}
	// Bureaucrat klaus("Klaus", 0);
	// Bureaucrat olaf("Olaf", 2999);

	std::cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << std::endl;
	return 0;
}