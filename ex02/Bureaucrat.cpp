/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 01:53:23 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/14 16:58:54 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("default Bureaucrat"), grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &n, int g): name(n)
{
	if (g > 150)
		throw GradeTooLowException();
	if (g < 1)
		throw GradeTooHighException();
	grade = g;
	std::cout << "Bureaucrat " << name << " created, with grade of " << grade << " constructor called"<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment called" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name << " Destructor called, Bureaucrat Go Boom" << std::endl;
}

const	std::string& Bureaucrat::getName() const
{
	return (this->name);
}

int		Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
	throw GradeTooLowException();
	this->grade += 1;
}

void	Bureaucrat::signForm(AForm& f)
{
	if (this->grade > f.getGradeSign())
		std::cout << "Bureaucrat " << name << " with grade " << this->grade << " couldn't sign Form " << f.getFormName() << " because credit score too low" << std::endl;
	else {
		std::cout << "Bureaucrat " << name << " with grade " << this->grade << " signed Form " << f.getFormName() << std::endl;
		f.beSigned(*this);
	}

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", buraucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	form.execute(*this);
    std::cout << this->name << " executes " << form.getFormName() << "." << std::endl;
}
