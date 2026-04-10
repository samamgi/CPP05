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

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &new_target) : AForm("RobotomyRequestForm", 72, 45), target(new_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm("RobotomyRequestForm", 72, 45), target(copy.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	this->target = copy.getTarget();
	return (*this);
}

void	RobotomyRequestForm::setTarget(std::string const &new_target)
{
	this->target = new_target;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return(this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
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
