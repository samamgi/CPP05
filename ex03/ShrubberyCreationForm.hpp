/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:16:28 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/06 11:16:29 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORMCLASS_HPP
# define SHRUBBERYCREATIONFORMCLASS_HPP

# include "AForm.hpp"
# include <iomanip>
# include <iostream>
# include <string>

class ShrubberyCreationForm : public AForm
{
  private:
	std::string target;

  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const &new_target);
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

    void setTarget(std::string const &new_target);
    std::string getTarget() const;

    void execute(Bureaucrat const &executor) const;
};

#endif
