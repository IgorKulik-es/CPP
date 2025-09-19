/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:15:27 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/19 13:16:33 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template<class T>
void	swap(T& a, T& b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template<class T>
T	min(T a, T b)
{
	if (a < b)
		return (a);
	return (b);
}

template<class T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
