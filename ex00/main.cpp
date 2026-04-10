/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:14:01 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/02 12:29:45 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	// Bureaucrat	dflt;
	// std::cout << dflt;
	// Bureaucrat typ("type");
	// std::cout << typ;
	// Bureaucrat a("a");
	// Bureaucrat b(a);
	// std::cout << b;
	// try
	// {
	//     std::cout << "Insert a name for the Bureaucrat: ";
	//     std::string name;
	//     std::getline(std::cin, name);
	//     std::cout << "Insert a grade for the Bureaucrat: ";
	//     int grade;
	//     std::cin >> grade;
	// 	Bureaucrat specific(name, grade);
	// 	std::cout << specific;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// catch (std::invalid_argument &e)
	// {
	// }
	std::cout << std::endl;
	std::cout << "Testing Exceptions:" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "Testing Grade Too High Exception:" << std::endl;
	try
	{
		Bureaucrat High("High", 0);
		std::cout << High;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Testing Grade Too Low Exception:" << std::endl;
	try
	{
		Bureaucrat Low("Low", 151);
		std::cout << Low;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	Bureaucrat valid149("Valid149", 149);
	Bureaucrat valid2("Valid2", 1);
	std::cout << std::endl;
	std::cout << "Testing Increment and Decrement:" << std::endl;
	try
	{
		std::cout << "Before Increment: " << valid149 << std::endl;
		valid149.incrementGrade();
		std::cout << "After Increment: " << valid149 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Before Decrement: " << valid2 << std::endl;
		valid2.decrementGrade();
		std::cout << "After Decrement: " << valid2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat valid1("Valid1", 1);
	Bureaucrat valid150("Valid150", 150);
	std::cout << std::endl;
	std::cout << "Testing Increment and Decrement Exceptions:" << std::endl;
	std::cout << "-------------------" << std::endl;
	try
	{
		std::cout << "Before Increment: " << valid1 << std::endl;
		valid1.incrementGrade();
		std::cout << "After Increment: " << valid1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Before Decrement: " << valid150 << std::endl;
		valid150.decrementGrade();
		std::cout << "After Decrement: " << valid150 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}
