/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:45:35 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/14 13:10:54 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm() : name("default AForm"), gradeSign(150), gradeExe(150), isSigned(false)
{
	std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(const std::string &n, int gs, int ge): name(n), gradeSign(gs), gradeExe(ge)
{
	check_valid_grade(gs);
	check_valid_grade(ge);
	std::cout << "AForm " << name << " created, with required grade of signing of " << gradeSign << " and execution " << gradeExe << " constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), gradeSign(other.gradeSign), gradeExe(other.gradeExe), isSigned(false)
{
	std::cout << "AForm Copy Constructor Called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assignment called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << name << " Destructor called, AForm Go Boom" << std::endl;
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->gradeSign)
	{
		this->isSigned = true;
	}
	else
		throw AForm::GradeTooLowSignException();
}

void	AForm::check_valid_grade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char* AForm::GradeTooLowSignException::what() const throw()
{
	return "AForm Grade is higher than Bureaucrat's aura!";
}

const char* AForm::GradeTooLowExeException::what() const throw()
{
	return "AForm Grade to Execute is higher than Bureaucrat's power level";
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << "AForm NAME: " << f.getFormName() << "\n" <<
	"Grade to SIGN: " << f.getGradeSign() << "\n" <<
	"Grade to EXECUTE: " << f.getGradeExe() << "\n" <<
	"Is AForm SIGNED: " << f.getIsSigned() << std::endl;
	return out;
}

int	AForm::getGradeSign() const
{
	return this->gradeSign;
}

int	AForm::getGradeExe() const
{
	return this->gradeExe;
}

bool	AForm::getIsSigned() const
{
	return this->isSigned;
}


std::string	AForm::getFormName() const
{
	return this->name;
}
