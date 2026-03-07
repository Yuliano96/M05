/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 11:15:01 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/07 20:25:06 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "iostream"

int main()
{
	try
	{
		std::cout << "==== case 1: sign success ====\n";
		Bureaucrat b("Pedro Sanchez", 1);
		Form f("construction contract", 7, 8);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	{
		std::cout << "==== case 2: sign fail ====\n";
		Bureaucrat b("Zapatero", 5);
		Form f("pardon permit", 3, 7);
		b.signForm(f);
	}
	try
	{
		std::cout << "==== case 3: invalid form ====\n";
		Form f("invalid form", 0, 9);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}