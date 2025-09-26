/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:22:38 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/23 19:04:32 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
typename T::iterator	easyfind( T& arr, int num )
{
	typename T::iterator	iter_find;

	iter_find = std::find(arr.begin(), arr.end(), num);
	if (iter_find != arr.end())
		return (iter_find);
	throw 0;
	return (iter_find);
}

