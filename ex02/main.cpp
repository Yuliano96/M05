/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:52:12 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/09 21:36:16 by yuliano          ###   ########.fr       */
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
		Bureaucrat burocratras[] = {Bureaucrat("Pedro Sanchez", 3), Bureaucrat("Zapatero", 4), Bureaucrat("Trump", 1)};
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

	
	{
		std::cout<<"\n===============\n";
		Bureaucrat boss("Boss", 20);
		Bureaucrat exe("exe", 6);
		PresidentialPardonForm form("Arthur Dent");

		std::cout<<"====boss========\n";
		boss.signForm(form);
		std::cout<<"=======executor====\n";
		exe.executeForm(form);
		//void executeForm(AForm const &form) const;
		//se pasa el objeto como referencia a la clase base.
		//upcasting implícito
	}
	
}