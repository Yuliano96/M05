/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:34:54 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/08 14:42:09 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef  SHRUBBERY_CREATION_FORN_HPP
#define  SHRUBBERY_CREATION_FORN_HPP

#include "AForm.hpp"

class ShrubberyCreationForm:public AForm
{
	private:
	
	std::string target;

	public:
	
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &_target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	void delegatesExecution() const;
};


#endif