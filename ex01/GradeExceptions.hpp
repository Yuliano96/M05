/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeExceptions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:37:29 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/07 20:30:53 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_EXCEPTIONS_HPP
#define GRADE_EXCETIONS_HPP

#include <exception>

class GradeTooHighException:public std::exception
	{
		public:
		const char *what() const throw()
		{
			return "Grade too high";
		}
		
	};
	
	class GradeTooLowException:public std::exception
	{
		public:
		const char *what() const throw()
		{
			return "Grade too low";
		}
	};

#endif