/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:39:15 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/23 19:05:35 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <vector>
# include <list>
# include <algorithm>
# include <iostream>

template <typename T, typename T::iterator>
typename T::iterator	easyfind( T& arr, int num );

# include "easyfind.tpp"

#endif
