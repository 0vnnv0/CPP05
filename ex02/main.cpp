/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:37:41 by anschmit          #+#    #+#             */
/*   Updated: 2025/05/07 18:00:47 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
int	main()
{
	ShrubberyCreationForm b("tax");
	b.action();

	PresidentialPardonForm c("tax2");
	c.action();
	return 0;
}