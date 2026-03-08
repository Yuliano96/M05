/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:03:38 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/08 13:42:19 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
	
	const std::string name;
	bool	isSigned;
	const int gradeToSig;
	const int gradeToExecute;
	int		checkGrade(int grade);

	public:
	
	AForm();
	AForm(const std::string &_name, const int _gradeToSig, const int gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSig() const;
	int getGradeToExcute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	void	execute(Bureaucrat const &executor) const;
	virtual void	delegatesExecution() const = 0;
	
	class GradeTooHighException:public std::exception
	{
		public:
		const char *what() const throw();
	};
	
	class GradeTooLowException:public std::exception
	{
		public:
		const char *what() const throw();
	};
	
	class FormNotSignedException:public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);
	
#endif