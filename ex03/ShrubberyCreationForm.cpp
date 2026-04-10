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

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &new_target) : AForm("ShrubberyCreationForm",
	145, 137), target(new_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm("ShrubberyCreationForm", 145, 137),
	target(copy.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	this->target = copy.target;
	return (*this);
}

void ShrubberyCreationForm::setTarget(std::string const &new_target)
{
	this->target = new_target;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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
	file.close();
}
