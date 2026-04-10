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
	std::string const new_grade) : name(new_name)
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

int	checkstring(std::string const new_grade)
{
	int	i;

	i = 0;
	if (new_grade[i] == '-' || new_grade[i] == '+')
		i++;
	while (new_grade[i])
	{
		if (new_grade[i] < '0' || new_grade[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	checkerror(std::string const new_grade)
{
	int	check;

	if (checkstring(new_grade) == -1)
		throw(std::invalid_argument("Invalid Arguments inserted !"));
	check = atoi(new_grade.c_str());
	if (check < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (check > 150)
		throw(Bureaucrat::GradeTooLowException());
	return (check);
}

void Bureaucrat::setGrade(std::string const new_grade)
{
	this->grade = checkerror(new_grade);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade Too Low !");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade Too High !");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &type)
{
	out << type.getName() << ", bureaucrat grade " << type.getGrade() << "." << std::endl;
	return (out);
}
