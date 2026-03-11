/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:56:37 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/11 21:53:56 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
	std::cout<<"Intern default constructor\n";
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout<< "Inter copy constructor\n";
}

Intern &Intern::operator=(const Intern &other)
{
	if(this != &other)
	{
		
	}
	std::cout<< "Intern assignment operator\n";
	return *this;
}

Intern::~Intern()
{
	std::cout<<"Intern destroyed\n";
}

int Intern::getType(const std::string &nameForm)
{
	std::string type[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for(int i = 0; i < 3; i++)
	{
		if (nameForm == type[i])
			return (i);
	}
	throw Intern::UnknownFormType();
}

AForm *Intern::makeForm(const std::string &nameForm, 
			const std::string &target)
{
	AForm *form;
	int type; 
	try
	{
		type = getType(nameForm);
	
		switch (type)
		{
			case 0:
				form = new ShrubberyCreationForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new PresidentialPardonForm(target);
			break;
		
		};
		
		std::cout<< "Intern creates "<< nameForm << std::endl;
		return form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}