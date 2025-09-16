/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:19:14 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/16 07:53:09 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned()) {
		throw AForm::GradeTooLowSignException();
	}
	if (executor.getGrade() > getGradeExe()) {
		throw AForm::GradeTooLowException();
	}

	std::cout << "* VZZZZZZZZ... BZZZZ... BZZZZ... *" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy for " << this->target << " failed." << std::endl;
	}
}
