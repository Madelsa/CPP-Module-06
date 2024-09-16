/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:28:31 by mahmoud           #+#    #+#             */
/*   Updated: 2024/09/16 20:27:46 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        std::cout << "Invalid input format." << std::endl;
        return 1;
    }
    std::string input = argv[1];
    ScalarConverter::convert(input);
}
