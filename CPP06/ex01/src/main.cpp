/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:54:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/18 18:48:30 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int	main( void )
{
	Data		object;
	uintptr_t	ptr_int;
	Data		*ptr_data;

	object.x = 10;
	object.y = -42;
	object.c_1 = 'c';
	object.c_2 = '&';
	std::cout << "Instantialed object with address:\t" << &object << std::endl;
	ptr_int = Serializer::serialize(&object);
	std::cout << "Address cast into uintptr_t:\t\t" << ptr_int << std::endl;
	ptr_data = Serializer::deserialize(ptr_int);
	std::cout << "Deserialized address:\t\t\t" << ptr_data << std::endl;
	std::cout << "Contents of object\t\t\t" << ptr_data->x << " " << ptr_data->c_1 << " " << ptr_data->y << " " << ptr_data->c_2 << std::endl;
	std::cout << "Object size\t\t\t\t" << sizeof(Data) << std::endl;
	return (0);
}
