/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:29:54 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/19 12:22:14 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Functions.hpp"

// class Z: public Base {};

int main() 
{
    srand(time(0));
    Base* base = generate();
    identify(base);
    identify(*base);
    // Base* baseTest = new Z;
    // identify(baseTest);
    // identify(*baseTest);
    delete base;
    // delete baseTest;
}