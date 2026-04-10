/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 09:48:55 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/02 12:35:07 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <climits>

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const new_name) : name(new_name), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name),
	grade(copy.grade)
{
}

Bureaucrat::Bureaucrat(std::string const new_name,
	int new_grade) : name(new_name)
{
	this->setGrade(new_grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade > 1)
	{
		(this->grade)--;
		return ;
	}
	throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::decrementGrade()
{
	if (this->grade < 150)
	{
		(this->grade)++;
		return ;
	}
	throw(Bureaucrat::GradeTooLowException());
}

int	checkerror(int new_grade)
{
	if (new_grade == INT_MAX)
		throw(Bureaucrat::GradeTooHighException());
	if (new_grade == INT_MIN)
		throw(Bureaucrat::GradeTooLowException());
	if (new_grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (new_grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	return (new_grade);
}

void Bureaucrat::setGrade(int new_grade)
{
	this->grade = checkerror(new_grade);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade Too Low !");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade Too High !");
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &type)
{
	out << type.getName() << ", bureaucrat grade " << type.getGrade() << "." << std::endl;
	return (out);
}
