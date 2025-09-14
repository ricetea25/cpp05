/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:29:09 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/14 15:12:52 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > getGradeExe()) {
		throw AForm::GradeTooLowException();
	}

	std::string filename = this->target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile.is_open()) {
		std::cerr << "Error: Could not open file for writing." << std::endl;
		return;
	}

	outfile << "      /\\      " << std::endl;
	outfile << "     /\\*\\     " << std::endl;
	outfile << "    /\\O\\o\\    " << std::endl;
	outfile << "   /\\*\\O\\/\\   " << std::endl;
	outfile << "  /\\O\\/\\*\\o\\  " << std::endl;
	outfile << " /\\*\\o\\/\\O\\/\\ " << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << "      ||      " << std::endl;

	outfile.close();

	std::cout << "ShrubberyCreationForm executed successfully by " << executor.getName() << "." << std::endl;
}
