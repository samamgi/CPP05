/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:06:00 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/06 13:32:34 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RRF::RRF() : AForm("RobotomyRequestForm", "72", "45"), target("Default")
{
}

RRF::RRF(std::string const &new_target) : AForm("RobotomyRequestForm", "72", "45"), target(new_target)
{
}

RRF::RRF(RRF const &copy) : AForm("RobotomyRequestForm", "72", "45"), target(copy.getTarget())
{
}

RRF::~RRF()
{
}

RRF	&RRF::operator=(RRF const &copy)
{
	this->target = copy.getTarget();
	return (*this);
}

void	RRF::setTarget(std::string const &new_target)
{
	this->target = new_target;
}

std::string	RRF::getTarget() const
{
	return(this->target);
}

void	RRF::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > 45)
	{
		throw (AForm::GradeTooLowException());
		return;
	}
	if (AForm::getSign() == false)
	{
		throw(AForm::NotSignedException());
		return;
	}
	std::cout << " * Making drilling noises * " << std::endl;
	srand(time(NULL));
	if ((rand() % 2) == 0)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}
