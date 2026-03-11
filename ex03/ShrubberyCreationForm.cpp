/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:45:07 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/08 18:19:06 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm():
						AForm("Shrubbery Creation Form", 145, 137),target("target")
{
	std::cout<<"ShrubberyCreationForm default constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target):
						AForm("Shrubbery Creation Form", 145, 137),target(_target)
{
	std::cout<<"ShrubberyCreationForm alternative constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
					AForm(other),target(other.target)
{
	std::cout<<"ShrubberyCreationForm copy constructor\n";
} 

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout<< "ShrubberyCreationForm assignment operator\n";
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm destroyed\n";
}

void	ShrubberyCreationForm::delegatesExecution() const
{
	std::ofstream	file;
	std::string		filename;

	filename = this->target + "_shrubbery";
	file.open(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open shrubbery file");

	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\\n";
	file << std::endl;
	file << "       ccee88oo\n";
	file << "    C8O8O8Q8PoOb o8oo\n";
	file << "  dOB69QO8PdUOpugoO9bD\n";
	file << " CgggbU8OU qOp qOdoUOdcb\n";
	file << "    6OuU  /p u gcoUodpP\n";
	file << "      \\\\//  /douUP\n";
	file << "        \\\\////\n";
	file << "         |||/\\\n";
	file << "         |||\\/\n";
	file << "         |||||\n";
	file << "   .....//||||\\....\n";
	file.close();
	std::cout<<"built tree\n";
}