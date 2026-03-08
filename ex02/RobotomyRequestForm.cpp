/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:31:34 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/08 18:01:00 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():AForm("Robotics Application Form", 72, 45),
										target("target")
{
	std::cout<<"RobotomyRequestForm default constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target):AForm("Robotics Application Form", 72, 45),
										target(_target)
{
	std::cout<<"RobotomyRequestForm alternative constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other),
										target(other.target)
{
	std::cout<<"RobotomyRequestForm copy constructor\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout<< "RobotomyRequestForm assignment operator\n";
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestForm destroyed\n";
}


void RobotomyRequestForm::delegatesExecution() const
{
    static bool seeded = false;

    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }

    std::cout << "Brrrrrrrr... drilling noises..." << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;
}