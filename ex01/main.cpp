/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:48:37 by rteoh             #+#    #+#             */
/*   Updated: 2025/09/14 12:28:51 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Alice", 100);
		Form f("Furry_convention", 42, 42);
		
		std::cout << "Form signed: " << f.getIsSigned() << std::endl;
		a.signForm(f);
		std::cout << "Form signed: " << f.getIsSigned() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
