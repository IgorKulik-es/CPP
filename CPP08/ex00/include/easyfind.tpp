/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:22:38 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/29 15:09:46 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
typename T::iterator	easyfind( T& arr, int num )
{
	typename T::iterator	iter_find;

	iter_find = std::find(arr.begin(), arr.end(), num);
	if (iter_find != arr.end())
		return (iter_find);
	throw NO_VALUE_FOUND;
	return (iter_find);
}

