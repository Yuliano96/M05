/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:52:12 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/11 21:52:52 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
//#include "AForm.hpp"
#include <iostream>

int main()
{

	Intern					intern;
	
	AForm *bushForm = intern.makeForm("shrubbery creation", "Major's house");
	std::cout << *bushForm;
	std::cout<<"=====================\n";
	AForm *robotomy = intern.makeForm("robotomy request", "robotics engineer");
	std::cout << *robotomy;
	std::cout<<"===================\n";
	AForm *pardon = intern.makeForm("presidential pardon", "Doctor");
	std::cout << *pardon;
	std::cout<<"======================\n";
	AForm *random = intern.makeForm("non existant form", "Doctor");
	(void)random;

	std::cout << std::endl;
	
}