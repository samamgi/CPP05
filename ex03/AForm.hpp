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

#ifndef AFORMCLASS_HPP
# define AFORMCLASS_HPP

# include "Bureaucrat.hpp"
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

class	Bureaucrat;

class AForm
{
  private:
	std::string const name;
	bool is_signed;
	int const grade_sign;
	int const grade_exe;

  public:
	AForm();
	AForm(std::string const &new_name);
	AForm(std::string const &new_name, std::string const &new_grade_sign,
		std::string const &new_grade_exe);
	AForm(AForm const &copy);
	virtual ~AForm();
	AForm &operator=(AForm const &copy);

	std::string getName() const;
	bool getSign() const;
	int getGradeSign() const;
	int getGradeExe() const;

	void beSigned(Bureaucrat const &value);

	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class NotSignedException : public std::exception
	{
		public :
		virtual const char*what() const throw();
	};
};
std::ostream &operator<<(std::ostream &out, AForm &type);
#endif
