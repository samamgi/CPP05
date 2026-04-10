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

class PPF : public AForm
{
  private:
	std::string target;

  public:
	PPF();
	PPF(std::string const &new_target);
	PPF(PPF const &copy);
	~PPF();
	PPF &operator=(PPF const &copy);

	void setTarget(std::string const &new_target);
	std::string getTarget() const;
    
	void execute(Bureaucrat const &executor) const;
};

#endif
