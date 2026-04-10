/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 09:31:20 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/02 09:33:11 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATCLASS_HPP
# define BUREAUCRATCLASS_HPP

# include "Form.hpp"
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

class	Form;

class Bureaucrat
{
  private:
	const std::string name;
	int grade;

  public:
	Bureaucrat();
	Bureaucrat(std::string const new_name);
	Bureaucrat(std::string const new_name, std::string const new_grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	virtual ~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
	void setGrade(std::string const new_grade);

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &type);

#endif
