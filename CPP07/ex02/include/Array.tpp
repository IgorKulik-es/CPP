/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:39:15 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/19 15:38:06 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	this->arr_size = 0;
	this->elements = 0;
}

template <class T>
Array<T>::Array(unsigned int n)
{
	this->arr_size = n;
	this->elements = new T[n];
}

template <class T>
Array<T>::Array( const Array& copy )
{
	this->arr_size = 0;
	*this = copy;
}

template <class T>
Array<T>::~Array()
{
	if (this->arr_size > 0)
		delete[] this->elements;
}

template <class T>
Array<T>&	Array<T>::operator=( const Array& copy )
{
	if (this->arr_size > 0)
		delete[] this->elements;
	this->arr_size = copy.size();
	this->elements = new T[this->arr_size];
	for (unsigned int i = 0; i < this->arr_size; i++)
		(this->elements)[i] = copy[i];
	return (*this);
}

template <class T>
T&	Array<T>::operator[]( unsigned int idx )
{
	if (idx >= this->arr_size)
		throw std::out_of_range("std::out_of_range");
	return ((this->elements)[idx]);
}

template <class T>
const T&	Array<T>::operator[]( unsigned int idx ) const
{
	if (idx >= this->arr_size)
		throw std::out_of_range("std::out_of_range");
	return ((this->elements)[idx]);
}

template <class T>
unsigned int	Array<T>::size( void ) const
{
	return (this->arr_size);
}
