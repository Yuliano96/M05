/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:13:00 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/04 21:13:56 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

int Bureaucrat::checkGrade(int _grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	return _grade;	
}

Bureaucrat::Bureaucrat():name("Default"), grade(150)
{
	std::cout << "Default constructor\n";
}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade):name(_name),grade(checkGrade(_grade))
{
	std::cout << "Alternative constructor\n";                                             
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		/*El nombre no se puede modificar*/
		this->grade = other.grade;
	}
	std::cout << "assignment operator\n";
	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destroyer\n";
}

void Bureaucrat::increaseGrade()
{
	grade = checkGrade(grade - 1);
}

void Bureaucrat::decreaseGrade()
{
	grade = checkGrade(grade + 1);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}