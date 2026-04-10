/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:03:32 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/06 13:03:36 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORMCLASS_HPP
# define ROBOTOMYREQUESTFORMCLASS_HPP

# include "AForm.hpp"
# include <iomanip>
# include <iostream>
# include <string>

class RobotomyRequestForm : public AForm
{
    private: 
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &new_target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

        void setTarget(std::string const &new_target);
        std::string getTarget() const;

        void execute(Bureaucrat const &executor) const;
};

#endif
