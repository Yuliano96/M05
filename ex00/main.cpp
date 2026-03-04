/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:00:05 by ypacileo          #+#    #+#             */
/*   Updated: 2026/03/04 21:19:58 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "======== a =======" << std::endl;
        Bureaucrat a("Alejandro", -1);
        std::cout << a << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "========b=========" << std::endl;
        Bureaucrat b("pedro", 1);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "========c=========" << std::endl;
        Bureaucrat b ("pedro", 1);
        Bureaucrat c;
        c = b;
        std::cout << c << std::endl;
        c.increaseGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "========================" << std::endl;
    try
    {
        Bureaucrat b("pedro sanchez", 149);
        b.decreaseGrade();
        std::cout << b << std::endl;
        b.decreaseGrade();
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}