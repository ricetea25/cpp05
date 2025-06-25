/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:45:37 by rteoh             #+#    #+#             */
/*   Updated: 2025/06/25 03:34:49 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <string>

class Form
{
	private:
		const std::string	name;
		const int			gradeSign;
		const int			gradeExe;
		bool				isSigned;
	public:
		Form();
		Form(const std::string& n, int grade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const	std::string& getName() const;
		int		getGrade() const;
		void	check_valid_grade(int grade);
		void	beSigned()
		void	incrementGrade();
		void	decrementGrade();

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
		private:
			std::string msg;
		public:
			const char* what() const throw();
	};
	class notExecutedException : public std::excpetion
	{
		public:
			const char* what() const throw();
	};

};
