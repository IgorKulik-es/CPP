/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:16:29 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/18 18:43:17 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct s_data Data;

class	Serializer
{
	public:
		Serializer();
		Serializer( const Serializer& copy );
		virtual ~Serializer() = 0;
		void		operator=( const Serializer& copy );
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
