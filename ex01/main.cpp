/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:13:51 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/17 16:27:52 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() 
{
    Data data;

    data.intTest = 1;
    data.strTest = "test";

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized raw value (uintptr_t): " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    if (deserializedData == &data) 
    {
        std::cout << "Deserialized int: " << deserializedData->intTest << std::endl;
        std::cout << "Deserialized str: " << deserializedData->strTest << std::endl;
    } 
    else 
        std::cout << "Serialization and deserialization failed." << std::endl;
}
