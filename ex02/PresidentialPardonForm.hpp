/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:38:00 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/06 13:38:04 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORMCLASS_HPP
# define PRESIDENTIALPARDONFORMCLASS_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	std::string target;

  public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &new_target);
	PresidentialPardonForm(PresidentialPardonForm const &copy);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

	void setTarget(std::string const &new_target);
	std::string getTarget() const;
    
	void execute(Bureaucrat const &executor) const;
};

#endif
