/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:52:12 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/08 18:22:49 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout<<"=============constructor burocratas==========\n";
		Bureaucrat burocratras[] = {Bureaucrat("Pedro Sanchez", 4), Bureaucrat("Zapatero", 5), Bureaucrat("Trump", 1)};
		std::cout<<"===============================================\n";
		std::cout<<"================constructor Form================\n";
		AForm *form[] = {new PresidentialPardonForm("Arthur Dent"), new ShrubberyCreationForm("house"), new RobotomyRequestForm("drill")};
		std::cout<<"===============================================\n";

		std::cout<<"======signed forms===============\n";
		for (int i = 0; i < 3; i++)
			burocratras[i].signForm(*form[i]);
		std::cout<<"=========execute==============\n";
		for(int i = 0; i < 3; i++)
		{
			form[i] ->execute(burocratras[i]);
		}
		std::cout<<"=========Destructors=========\n";
		for(int i = 0; i < 3; i++)
			delete form[i];
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}