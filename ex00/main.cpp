/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:00:05 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/01 18:37:30 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout<<"======== a =======\n";
        Bureaucrat a("Alejandro", -1);
        std::cout<< a;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout<<"========b=========\n";
        Bureaucrat b("pedro", 1);
        std::cout<< b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout<<"========c=========\n";
        Bureaucrat b ("pedro", 1);
        Bureaucrat c;
        c = b;
        c.increaseGrade();
        std::cout<< c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
}