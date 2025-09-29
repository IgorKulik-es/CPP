/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:08:18 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/29 14:41:16 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
};

template <typename T>
MutantStack<T>::MutantStack( const MutantStack<T>& copy ): std::stack<T>(copy.get_c()){};

template <typename T>
MutantStack<T>::~MutantStack(){};

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=( const MutantStack<T>& copy )
{
	this->c = copy.get_c();
}

template <typename T>
const std::deque<T>&	MutantStack<T>::get_c( void ) const
{
	return (this->c);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void )
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void )
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin( void ) const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end( void ) const
{
	return (this->c.end());
}
