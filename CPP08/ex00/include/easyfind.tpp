/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:22:38 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/19 18:14:39 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <template <int> typename T>
const T::iterator	easyfind(const T& arr, int idx)
{
	T&	first_find;

	first_find = T.find(idx);
	if (first_find != T.end())
		return (first_find);
	return (0);
}

