/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:25:49 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/18 11:57:15 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int random = rand() % 3;

    if (random == 0) 
        return new A;
    else if (random == 1)
        return new B;
    else 
        return new C;
}

void    identify(Base* p) 
{

    if (dynamic_cast<A*>(p)) 
        std::cout << "from_pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "from_pointer: B" << std::endl;
    else if ( dynamic_cast<C*>(p))
        std::cout << "from_pointer: C" << std::endl;
    else
        std::cout << "from_pointer: Unknown type" << std::endl;
    return;
}

void    identify(Base& p) 
{
    if ( dynamic_cast<A*>(&p))
        std::cout << "from_reference: A" << std::endl;
    else if ( dynamic_cast<B*>( &p ))
        std::cout << "from_reference: B" << std::endl;
    else if ( dynamic_cast<C*>(&p)) 
        std::cout << "from_reference: C" << std::endl;
    else
        std::cout << "from_reference: Unknown type" << std::endl;
    return;
}