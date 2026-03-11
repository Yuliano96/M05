/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:42:46 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/08 16:36:53 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():AForm("Presidential Pardon Form", 25, 5),target("target")
{
	std::cout<< "PresidentialPardonForm default constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target):
						AForm("Presidential Pardon Form", 25, 5),target(_target)
{
	std::cout<<"PresidentialPardonForm alternative constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other),target(other.target)
{
	std::cout<< "PresidentialPardonForm copy constructor\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout<< "PresidentialPardonForm assignment operator\n";
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm Destroyed\n";
}

void PresidentialPardonForm::delegatesExecution() const
{
	
	std::cout<<"Informs that "<<target<< "has been pardoned by Zaphod Beeblebrox"<<std::endl;
}