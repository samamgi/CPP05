/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:12:24 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/09 19:29:49 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(Intern const &);
		~Intern();

		Intern	&operator=(Intern const &);
		
		AForm	*makeForm(std::string const &name, std::string const &target);
};
