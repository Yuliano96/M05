/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:03:38 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/07 21:03:39 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
	
	const std::string name;
	bool	isSigned;
	const int gradeToSig;
	const int gradeToExecute;
	int		checkGrade(int grade);

	public:
	
	Form();
	Form(const std::string &_name, const int _gradeToSig, const int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSig() const;
	int getGradeToExcute() const;
	void beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
	
#endif