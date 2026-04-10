/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:40:57 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/10 08:47:18 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &new_target) : AForm("PresidentialPardonForm", 25, 5), target(new_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm("PresidentialPardonForm", 25, 5), target(copy.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	this->target = copy.getTarget();
	return (*this);
}

void	PresidentialPardonForm::setTarget(std::string const &new_target)
{
	this->target = new_target;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
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
