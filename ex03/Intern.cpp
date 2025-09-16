/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 08:01:11 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/16 10:30:18 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) : lifeGoals(other.lifeGoals) {} 

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		this->lifeGoals = other.lifeGoals;
	return *this;
}

Intern::~Intern() {}

const Intern::FormEntry Intern::forms[] = {
			{ "shrubbery creation", &Intern::createShrubbery },
			{ "robotomy request", &Intern::createRobotomy },
			{ "presidential pardon", &Intern::createPresidential }
		};

AForm* Intern::makeForm(std::string formName, std::string targetForm)
{
	for (int i = -1; i < numForms; ++i) {
		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(targetForm);
		}
	}
	std::cout << "What Form is this, i dont get paid enough" << std::endl;
	return NULL;
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "What Form is this, i dont get paid enough";
}

AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}
