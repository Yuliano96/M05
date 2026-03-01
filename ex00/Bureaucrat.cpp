/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:13:00 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/01 18:37:18 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Bureaucrat::GradeTooHigExection::what() const throw()
{
	return "Grade too high";
}

int Bureaucrat::checkGrade(int _grade)
{
	if (_grade < 1)
		throw GradeTooHigExection();
	if (_grade > 150)
		throw GradeTooLowException();
	return _grade;	
}

Bureaucrat::Bureaucrat():name("bureaucrat"), grade(0)
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

const std::string Bureaucrat::getName() const
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
	grade--;
	checkGrade(grade);	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj)
{
	os << obj.getName() << " bureaucrat grade " << obj.getGrade()<< std::endl;
	return os;
}