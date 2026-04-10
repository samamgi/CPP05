/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:47:14 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/05 11:32:09 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	checkerror(std::string const &grade)
{
	int	i;

	i = 0;
	if (grade[i] == '-' || grade[i] == '+')
		i++;
	while (grade[i])
	{
		if (grade[i] < '0' || grade[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	checkgrade(std::string const &grade)
{
	int	check;

	if (checkerror(grade) == -1)
		throw(std::invalid_argument("Invalid Arguments inserted !"));
	check = atoi(grade.c_str());
	if (check < 1)
		throw(Form::GradeTooHighException());
	if (check > 150)
		throw(Form::GradeTooLowException());
	return (check);
}

Form::Form() : name("Default"), is_signed(false), grade_sign(150),
	grade_exe(150)
{
}

Form::Form(std::string const &new_name) : name(new_name), is_signed(false),
	grade_sign(150), grade_exe(150)
{
}

Form::Form(std::string const &new_name, std::string const &new_grade_sign,
	std::string const &new_grade_exe) : name(new_name), is_signed(false),
	grade_sign(checkgrade(new_grade_sign)), grade_exe(checkgrade(new_grade_exe))
{
}

Form::Form(Form const &copy) : name(copy.name), is_signed(copy.is_signed),
	grade_sign(copy.grade_sign), grade_exe(copy.grade_exe)
{
}

Form::~Form()
{
}

Form &Form::operator=(Form const &copy)
{
	this->is_signed = copy.is_signed;
	return (*this);
}

std::string Form::getName()
{
	return (this->name);
}

bool Form::getSign()
{
	return (this->is_signed);
}

int Form::getGradeSign()
{
	return (this->grade_sign);
}

int Form::getGradeExe()
{
	return (this->grade_exe);
}

void Form::beSigned(Bureaucrat const &value)
{
	if (value.getGrade() > this->grade_sign)
	{
		throw(Form::GradeTooLowException());
		return ;
	}
	this->is_signed = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade Too Low !");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade Too High !");
}

std::ostream &operator<<(std::ostream &out, Form &type)
{
	out << type.getName() << " Form grade sign requiered " << type.getGradeSign() << " Form grade exec requiered " << type.getGradeExe() << " Form is signed " << std::boolalpha << type.getSign() << std::endl;

	return (out);
}