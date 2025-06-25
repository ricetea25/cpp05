/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 01:53:26 by rteoh             #+#    #+#             */
/*   Updated: 2025/06/24 19:16:39 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <string>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& n, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const	std::string& getName() const;
		int		getGrade() const;
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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
