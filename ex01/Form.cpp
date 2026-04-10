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
#include <climits>

int	checkgrade(int grade)
{
	if (grade == INT_MAX)
		throw(Form::GradeTooHighException());
	if (grade == INT_MIN)
		throw(Form::GradeTooLowException());
	if (grade < 1)
		throw(Form::GradeTooHighException());
	if (grade > 150)
		throw(Form::GradeTooLowException());
	return (grade);
}

Form::Form() : name("Default"), is_signed(false), grade_sign(150),
	grade_exe(150)
{
}

Form::Form(std::string const &new_name) : name(new_name), is_signed(false),
	grade_sign(150), grade_exe(150)
{
}

Form::Form(std::string const &new_name, int new_grade_sign,
	int new_grade_exe) : name(new_name), is_signed(false),
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