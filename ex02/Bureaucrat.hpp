/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:20:41 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/08 18:35:09 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>


class AForm;

class Bureaucrat
{
	private:
	
	const std::string	name;
	int					grade;
	int		checkGrade(int _grade);
	
	public:
	
	Bureaucrat();
	Bureaucrat(const std::string &_name, int _grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	const std::string &getName() const;
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();
	void signForm(AForm &form);
	void executeForm(AForm const & form) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif