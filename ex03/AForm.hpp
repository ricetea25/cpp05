/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:59:41 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/16 07:32:30 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			gradeSign;
		const int			gradeExe;
		bool				isSigned;
	public:
		AForm();
		AForm(const std::string& n, int gs, int ge);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const	std::string& getName() const;
		int		getGrade() const;
		void	check_valid_grade(int grade);
		void	beSigned(const Bureaucrat& b);
		void	incrementGrade();
		void	decrementGrade();
		int		getGradeSign() const;
		int		getGradeExe() const;
		bool	getIsSigned() const;
		std::string	getFormName() const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
		
		
	class GradeTooHighException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	
	class GradeTooLowSignException : public std::exception
	{
		public:
		const char* what() const throw();
	};

	class GradeTooLowExeException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	
};

std::ostream&	operator<<(std::ostream& out, const AForm& f);

#endif
