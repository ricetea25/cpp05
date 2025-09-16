/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:48:03 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/16 10:37:54 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;
    Bureaucrat b1("John", 5);
    Bureaucrat b2("Jane", 75);

    // Test Case 1: Create a valid form (RobotomyRequestForm)
    try {
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << "Form created successfully." << std::endl;
    form->beSigned(b2);
    std::cout << "Form signed successfully." << std::endl;
    form->execute(b1);
    std::cout << "Form executed successfully." << std::endl;
	} 
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	if (form) {
		delete form;
	}

    std::cout << "---------------------------------------" << std::endl;

    // Test Case 2: Create another valid form (PresidentialPardonForm)
    try {
        form = someRandomIntern.makeForm("presidential pardon", "Zaphod");
        if (form) {
            std::cout << "Form created successfully." << std::endl;
            form->beSigned(b1);
            form->execute(b1);
            delete form;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "---------------------------------------" << std::endl;

    // Test Case 3: Try to create an unknown form
    try {
		form = someRandomIntern.makeForm("unknown form", "Target");
		if (form) {
			delete form;
		}
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    return 0;
}
