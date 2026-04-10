/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:40:57 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/10 08:55:08 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PPF::PPF() : AForm("PresidentialPardonForm", "25", "5")
{
}

PPF::PPF(std::string const &new_target) : AForm("PresidentialPardonForm", "25", "5"), target(new_target)
{
}

PPF::PPF(PPF const &copy) : AForm("PresidentialPardonForm", "25", "5"), target(copy.getTarget())
{
}

PPF::~PPF()
{
}

PPF	&PPF::operator=(PPF const &copy)
{
	this->target = copy.getTarget();
	return (*this);
}

void	PPF::setTarget(std::string const &new_target)
{
	this->target = new_target;
}

std::string	PPF::getTarget() const
{
	return (this->target);
}

void	PPF::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > 5)
	{
		throw (AForm::GradeTooLowException());
		return ;
	}
	if (AForm::getSign() == false)
	{
		throw (AForm::NotSignedException());
		return ;
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
