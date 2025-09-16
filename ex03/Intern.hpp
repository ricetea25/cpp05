/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 07:58:00 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/16 10:01:27 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <stdexcept>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm* (*FormCreator)(const std::string&);

class Intern
{
	private:
		
		struct FormEntry {
			std::string name;
			FormCreator creator;
		};
		std::string lifeGoals;
		
		static const FormEntry forms[];
		static const int numForms = 3;

		static AForm* createShrubbery(const std::string& target);
		static AForm* createRobotomy(const std::string& target);
		static AForm* createPresidential(const std::string& target);

		
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		AForm* makeForm(std::string formName, std::string targetForm);
		
	class UnknownFormException : public std::exception
	{
		public:
			const char* what() const throw();
	};
		
};


#endif
