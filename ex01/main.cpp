/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:14:01 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/05 12:55:34 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	Bureaucrat Low("gradelowtosign", 4);
	try
	{
		Form specific("caca2", 5, 12);
		std::cout << std::endl << specific;
		Low.signForm(specific);
		std::cout << specific;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
