/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:48:37 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/13 23:55:23 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		// Valid example
		Bureaucrat a("Alice", 75);
		std::cout << a << std::endl;

		// Increment grade
		a.incrementGrade();
		std::cout << "After increment: " << a << std::endl;

		// Decrement grade
		a.decrementGrade();
		std::cout << "After decrement: " << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception during normal Bureaucrat test: " << e.what() << std::endl;
	}

	std::cout << "----------------------------------" << std::endl;

	try
	{
		// Grade is too high
		Bureaucrat b("Bob", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception during creation: " << e.what() << std::endl;
	}

	try
	{
		// Grade too low
		Bureaucrat c("Charlie", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception during creation: " << e.what() << std::endl;
	}

	std::cout << "----------------------------------" << std::endl;

	try
	{
		// Try incrementing beyond grade 1
		Bureaucrat d("Daisy", 1);
		std::cout << d << std::endl;
		d.incrementGrade();  // Should throw
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception during increment: " << e.what() << std::endl;
	}

	try
	{
		// Try decrementing beyond grade 150
		Bureaucrat e("Evan", 150);
		std::cout << e << std::endl;
		e.decrementGrade();  // Should throw
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception during decrement: " << e.what() << std::endl;
	}

	return 0;
	}
