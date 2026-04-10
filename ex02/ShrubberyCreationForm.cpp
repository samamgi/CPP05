/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:21:27 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/06 12:54:44 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

SBCF::SBCF() : AForm("ShrubberyCreationForm", "145", "137"), target("Default")
{
}

SBCF::SBCF(std::string const &new_target) : AForm("ShrubberyCreationForm",
	"145", "137"), target(new_target)
{
}

SBCF::SBCF(SBCF const &copy) : AForm("ShrubberyCreationForm", "145", "137"),
	target(copy.getTarget())
{
}

SBCF::~SBCF()
{
}

SBCF &SBCF::operator=(SBCF const &copy)
{
	this->target = copy.target;
	return (*this);
}

void SBCF::setTarget(std::string const &new_target)
{
	this->target = new_target;
}

std::string SBCF::getTarget() const
{
	return (this->target);
}

void SBCF::execute(Bureaucrat const &executor) const
{
	std::ofstream file;
	std::string filename;

	if (executor.getGrade() > 137)
	{
		throw(AForm::GradeTooLowException());
		return ;
	}
	if (this->getSign() == false)
	{
		throw(AForm::NotSignedException());
		return ;
	}
	filename = target + "_shrubbery";
	file.open(filename.c_str());
	if (!file)
	{
		throw(std::runtime_error("could not open file"));
		return ;
	}
	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\\n";
}
