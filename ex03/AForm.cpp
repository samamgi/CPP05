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

#include "AForm.hpp"

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
		throw(AForm::GradeTooHighException());
	if (check > 150)
		throw(AForm::GradeTooLowException());
	return (check);
}

AForm::AForm() : name("Default"), is_signed(false), grade_sign(150),
	grade_exe(150)
{
}

AForm::AForm(std::string const &new_name) : name(new_name), is_signed(false),
	grade_sign(150), grade_exe(150)
{
}

AForm::AForm(std::string const &new_name, std::string const &new_grade_sign,
	std::string const &new_grade_exe) : name(new_name), is_signed(false),
	grade_sign(checkgrade(new_grade_sign)), grade_exe(checkgrade(new_grade_exe))
{
}

AForm::AForm(AForm const &copy) : name(copy.name), is_signed(copy.is_signed),
	grade_sign(copy.grade_sign), grade_exe(copy.grade_exe)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &copy)
{
	this->is_signed = copy.is_signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSign() const
{
	return (this->is_signed);
}

int AForm::getGradeSign() const
{
	return (this->grade_sign);
}

int AForm::getGradeExe() const
{
	return (this->grade_exe);
}

void AForm::beSigned(Bureaucrat const &value)
{
	if (value.getGrade() > this->grade_sign)
	{
		throw(AForm::GradeTooLowException());
		return ;
	}
	this->is_signed = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form: Grade Too Low !");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form: Grade Too High !");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form: Not Signed !");
}

std::ostream &operator<<(std::ostream &out, AForm &type)
{
	out << type.getName() << " Form grade sign requiered " << type.getGradeSign() << " Form grade exec requiered " << type.getGradeExe() << " Form is signed " << std::boolalpha << type.getSign() << std::endl;

	return (out);
}