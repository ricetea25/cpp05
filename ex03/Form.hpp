/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:45:37 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/14 11:27:08 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			gradeSign;
		const int			gradeExe;
		bool				isSigned;
	public:
		Form();
		Form(const std::string& n, int gs, int ge);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

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
	
	class NotSignedException : public std::exception
	{
		public:
		const char* what() const throw();
	};

	class NotExecutedException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	
};

std::ostream&	operator<<(std::ostream& out, const Form& f);

#endif
