/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:13:00 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/08 18:42:15 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

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

Bureaucrat::Bureaucrat():name("DefaultBureaucrat"), grade(150)
{
	std::cout << "Bureaucrat Default constructor\n";
}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade):name(_name),grade(checkGrade(_grade))
{
	std::cout << "Bureaucrat Alternative constructor\n";                                             
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat Copy constructor\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		/*El nombre no se puede modificar*/
		this->grade = other.grade;
	}
	std::cout << "Bureaucrat assignment operator\n";
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
	std::cout << "Bureaucrat Destroyed\n";
}

void Bureaucrat::increaseGrade()
{
	grade = checkGrade(grade - 1);
}

void Bureaucrat::decreaseGrade()
{
	grade = checkGrade(grade + 1);
}

void Bureaucrat::signForm(AForm &form)
{

	try
	{
		form.beSigned(*this);
		std::cout<<this->name << " signed "<< form.getName()<< std::endl;
	}
	catch(const std::exception& e)
	{

		std::cerr << name << " couldn't sign "<< form.getName() 
					<< " because "<<e.what() << std::endl;;
	}
	
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}