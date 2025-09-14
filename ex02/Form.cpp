/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:45:35 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/14 12:25:04 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form() : name("default Form"), gradeSign(150), gradeExe(150), isSigned(false)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(const std::string &n, int gs, int ge): name(n), gradeSign(gs), gradeExe(ge)
{
	check_valid_grade(gs);
	check_valid_grade(ge);
	std::cout << "Form " << name << " created, with required grade of signing of " << gradeSign << " and execution " << gradeExe << " constructor called" << std::endl;
}

Form::Form(const Form& other) : name(other.name), gradeSign(other.gradeSign), gradeExe(other.gradeExe), isSigned(false)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form copy assignment called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << name << " Destructor called, Form Go Boom" << std::endl;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->gradeSign)
	{
		this->isSigned = true;
	}
	else
		throw Form::GradeTooLowException();
}

void	Form::check_valid_grade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char* Form::NotSignedException::what() const throw()
{
	return "Form Grade is higher than Bureaucrat's aura!";
}

const char* Form::NotExecutedException::what() const throw()
{
	return "Form Grade to Execute is higher than Bureaucrat's power level";
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << "Form NAME: " << f.getFormName() << "\n " <<
	"Grade to SIGN: " << f.getGradeSign() << "\n" <<
	"Grade to EXECUTE: " << f.getGradeExe() << "\n" <<
	"Is Form SIGNED: " << f.getIsSigned() << std::endl;
	return out;
}

int	Form::getGradeSign() const
{
	return this->gradeSign;
}

int	Form::getGradeExe() const
{
	return this->gradeExe;
}

bool	Form::getIsSigned() const
{
	return this->isSigned;
}


std::string	Form::getFormName() const
{
	return this->name;
}
