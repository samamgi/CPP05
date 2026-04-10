/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:14:01 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/06 13:53:47 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	ShrubberyCreationForm	sign("sign");
	Bureaucrat	signataire("president", 72);
	Bureaucrat	executant("executant", 5);
	RobotomyRequestForm	robot("vbla");
	PresidentialPardonForm	pardon("samy");

	signataire.signForm(sign);
	signataire.executeForm(sign);
	signataire.signForm(robot);
	signataire.executeForm(robot);
	executant.executeForm(robot);
	executant.signForm(pardon);
	executant.executeForm(pardon);
}
