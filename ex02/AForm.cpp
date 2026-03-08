/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:01:56 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/07 23:00:42 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

int AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return grade;
}

AForm::AForm():name("DefaultForm"),isSigned(false),\
			gradeToSig(150),gradeToExecute(150)
{
	std::cout<<"Form Default constructor\n";
}

AForm::AForm(const std::string &_name, const int _gradeToSig, const int _gradeToExecute)
	: name(_name), isSigned(false), gradeToSig(checkGrade(_gradeToSig)), gradeToExecute(checkGrade(_gradeToExecute))
{
	std::cout<<"Form Alternative constructor\n";
}

AForm::AForm(const AForm &other):name(other.name), isSigned(other.isSigned),  \
		gradeToSig(other.gradeToSig), gradeToExecute(other.gradeToExecute)
{
	std::cout<<"Form copy constructor\n";
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	std::cout<<"Form assignment operator\n";
	return *this;
	
}

AForm::~AForm()
{
	std::cout<<"Form Destroyed\n";
}


const std::string& AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSig() const
{
	return gradeToSig;
}

int AForm::getGradeToExcute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeToSig)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &execute) const
{
	if (!isSigned)
		throw "The form is not signed\n";
	delegatesExecution(execute);
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
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