/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:42:46 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/08 10:50:53 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target):
						AForm("Presidential", 25, 5),target(_target)
{
	std::cout<<"presidentialPardonForm alternative constructor\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardon Destroyed\n";
}