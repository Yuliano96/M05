/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:22:43 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/08 16:30:02 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTO_MY_REQUEST_FORM_HPP
#define ROBOTO_MY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm:public AForm
{
	private:
	
	std::string target;

	public:
	
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &_target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();
	void delegatesExecution() const;
};


#endif