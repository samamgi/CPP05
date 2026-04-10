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
	int		i;
	std::string code[3] = {"presidential pardon", "robotomy request",
		"shrubbery creation"};
	i = 0;
	while (i < 3)
	{
		if (code[i] == name)
			break;
		i++;
	}
	switch (i)
	{
		case 0 :
			return (std::cout << "Intern creates PresidentialPardon" << std::endl, new PPF(target));
		case 1 :
			return (std::cout << "Intern creates RobotomyRequest" << std::endl, new RRF(target));
		case 2 :
			return (std::cout << "Intern creates ShrubberyCreation" << std::endl, new SBCF(target));
	}
	std::cout << "Intern could not creates Form" << std::endl;
	return (NULL);
}
