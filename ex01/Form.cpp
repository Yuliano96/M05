/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:01:56 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/07 21:07:29 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

int Form::checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return grade;
}
Form::Form():name("DefaultForm"),isSigned(false),\
			gradeToSig(150),gradeToExecute(150)
{
	std::cout<<"Form Default constructor\n";
}

Form::Form(const std::string &_name, const int _gradeToSig, const int _gradeToExecute)
	: name(_name), isSigned(false), gradeToSig(checkGrade(_gradeToSig)), gradeToExecute(checkGrade(_gradeToExecute))
{
	std::cout<<"Form Alternative constructor\n";
}

Form::Form(const Form &other):name(other.name), isSigned(other.isSigned),  \
		gradeToSig(other.gradeToSig), gradeToExecute(other.gradeToExecute)
{
	std::cout<<"Form copy constructor\n";
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	std::cout<<"Form assignment operator\n";
	return *this;
	
}

Form::~Form()
{
	std::cout<<"Form Destroyed\n";
}


const std::string& Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSig() const
{
	return gradeToSig;
}

int Form::getGradeToExcute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeToSig)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}
std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os<<"Form: "<<obj.getName()<<std::endl;
	os<<"Grade to sign: "<<obj.getGradeToSig()<<std::endl;
	os<<"Grede to execute: "<<obj.getGradeToExcute()<<std::endl;
	if (obj.getIsSigned())
		os<<"Is it signed: "<<"YES\n";
	else
		os<<"Is it signed: "<<"NO\n";		

	return os;
}