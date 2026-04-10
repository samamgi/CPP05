/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:23:32 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/05 10:42:23 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMCLASS_HPP
# define FORMCLASS_HPP

# include "Bureaucrat.hpp"
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

class	Bureaucrat;

class Form
{
  private:
	std::string const name;
	bool is_signed;
	int const grade_sign;
	int const grade_exe;

  public:
	Form();
	Form(std::string const &new_name);
	Form(std::string const &new_name, std::string const &new_grade_sign,
		std::string const &new_grade_exe);
	Form(Form const &copy);
	~Form();
	Form &operator=(Form const &copy);

	std::string getName();
	bool getSign();
	int getGradeSign();
	int getGradeExe();

	void beSigned(Bureaucrat const &value);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &out, Form &type);
#endif
