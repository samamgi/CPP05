/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:14:01 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/10 09:15:08 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	SBCF	sign("sign");
	Bureaucrat	signataire("president", "72");
	Bureaucrat	executant("executant", "5");
	Bureaucrat	boss("boss", "1");
	RRF	robot("vbla");
	PPF	pardon("samy");
	Intern intern;
	std::string formName;
	std::string formTarget;

	std::cout << "Enter the form name: " << std::endl;
	getline(std::cin, formName);
	std::cout << "Enter the form target: " << std::endl;
	getline(std::cin, formTarget);
	AForm	*form = intern.makeForm(formName, formTarget);
	if (form != NULL)
	{
		signataire.signForm(*form);
		signataire.executeForm(*form);
		boss.signForm(*form);
		boss.executeForm(*form);
	}
	signataire.signForm(robot);
	signataire.executeForm(robot);
	executant.executeForm(robot);
	executant.signForm(pardon);
	executant.executeForm(pardon);
	if (form != NULL)
		delete form;
}
