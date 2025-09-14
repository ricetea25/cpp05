/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:48:37 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/14 16:50:16 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// A high-grade bureaucrat
	Bureaucrat highGradeBureaucrat("Zaphod Beeblebrox", 1);
	// A low-grade bureaucrat
	Bureaucrat lowGradeBureaucrat("Arthur Dent", 150);

	std::cout << "--- ShrubberyCreationForm Test ---" << std::endl;
	try
	{
		ShrubberyCreationForm shrubberyForm("home");
		std::cout << shrubberyForm << std::endl;

		highGradeBureaucrat.signForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;

		highGradeBureaucrat.executeForm(shrubberyForm);
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "--- RobotomyRequestForm Test ---" << std::endl;
	try
	{
		RobotomyRequestForm robotomyForm("Bender");
		std::cout << robotomyForm << std::endl;

		highGradeBureaucrat.signForm(robotomyForm);
		std::cout << robotomyForm << std::endl;

		highGradeBureaucrat.executeForm(robotomyForm);
		highGradeBureaucrat.executeForm(robotomyForm);
		highGradeBureaucrat.executeForm(robotomyForm);
		highGradeBureaucrat.executeForm(robotomyForm);
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "--- PresidentialPardonForm Test ---" << std::endl;
	try
	{
		PresidentialPardonForm pardonForm("Ford Prefect");
		std::cout << pardonForm << std::endl;

		lowGradeBureaucrat.signForm(pardonForm); // This should fail
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		PresidentialPardonForm pardonForm("Ford Prefect");
		std::cout << pardonForm << std::endl;

		highGradeBureaucrat.signForm(pardonForm);
		std::cout << pardonForm << std::endl;
		
		lowGradeBureaucrat.executeForm(pardonForm); // This should fail
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
