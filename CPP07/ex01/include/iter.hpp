/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:22:38 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/19 14:15:16 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<class T, typename Num>
void	iter(const T* arr, const Num& lenght, void (*func)(const T&))
{
	for (Num i = 0; i < lenght; i++)
		(*func)(arr[i]);
}

template<class T, typename Num>
void	iter(T* arr, const Num& lenght, void (*func)(T&))
{
	for (Num i = 0; i < lenght; i++)
		(*func)(arr[i]);
}

template<class T>
void	print_element(const T& element)
{
	std::cout << element << " ";
}

template<class T>
void	increment_element(T& element)
{
	element++;
}

#endif
