/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:12:24 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/10 09:06:32 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <new>

Intern::Intern()
{
}

Intern::Intern(Intern const &)
{
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &)
{
	return (*this);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
	int	i;
	AForm	*res = NULL;
	// char	*tab = NULL;

	std::string code[4] = {"presidential pardon", "robotomy request",
		"shrubbery creation", "NULL"};
	i = 0;
	while (i <= 3)
	{
		if (i == 3 || name == code[i])
		{
			// try
			// {

				switch (i)
				{
					case 0:
						// tab = new char[1000000000000000];
						// (void)tab;
						std::cout << "Intern creates PresidentialPardon" << std::endl;
						res = new PresidentialPardonForm(target);
						break;
					case 1:
						res = new RobotomyRequestForm(target);
						std::cout << "Intern creates RobotomyRequest" << std::endl;
						break;
					case 2:
						res = new ShrubberyCreationForm(target);
						std::cout << "Intern creates ShrubberyCreation" << std::endl;
						break;
					case 3:
						std::cout << "Intern could not create Form" << std::endl;
						return (NULL);
				}
			// }
			// // catch (const std::bad_alloc &e)
			// // {
			// // 	throw std::runtime_error("Memory allocation failed: " + std::string(e.what()));
			// // }
			return (res);
		}
		i++;
	}
	return (res);
}
